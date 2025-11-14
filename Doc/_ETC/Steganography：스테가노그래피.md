# Steganography：스테가노그래피

&nbsp; 스테가노그래피는 그리스어로 `감추어져있다` 라는 뜻인 stegano 와 `쓰다, 그리다` 라는 뜻인 graphos 의 합성어로, 보이는 곳에 메시지를 은밀히 숨기는 은닉법을 의미합니다.

&nbsp; 사진, 음악, 동영상 같은 일반적인 파일 안에 데이터를 숨기는 기술입니다.

## 비트 플레인：Bit Plane

&nbsp; 비트 플레인 분산 방식은 상위 비트로 갈수록 영향력이 크고, 하위 비트로 갈수록 인지성이 감소하는 것을 이용해 하위 비트에 비밀 정보를 삽입하는 방법입니다.

## 파일 포맷 시그니처 중첩：Dual-format file

&nbsp; 파일의 **헤더(header)**와 푸터(footer) 구조를 이용하는 방법입니다.

&nbsp; 예를 들어, 이미지 파일(JPEG, PNG 등)과 ZIP 파일은 둘 다 “시작”과 “끝”을 나타내는 고정된 바이트 패턴(시그니처)을 가지고 있습니다.

-   ZIP 파일은 50 4B 03 04 로 시작하고, 끝에는 50 4B 05 06 으로 마무리됩니다.
-   PNG 파일은 89 50 4E 47 0D 0A 1A 0A 로 시작하고, 49 45 4E 44 AE 42 60 82 로 끝납니다.

&nbsp; 따라서 누군가 하나의 파일 안에 두 개의 포맷 데이터를 이어붙이면, 그 파일은 상황에 따라 이미지처럼도, 압축파일처럼도 보일 수 있습니다.

## 파일 뒤 데이터 추가：Appended ZIP

&nbsp; 이미지 파일의 끝부분 이후에 ZIP 파일 데이터를 그냥 붙이는 것입니다.

```bash
cat picture.png secret.zip > hidden.png
```

&nbsp; 이렇게 하면 hidden.png는 여전히 이미지 뷰어로 열리지만, ZIP 파일의 구조가 그대로 들어 있어서 hidden.zip으로 바꿔 압축 해제하면 내부 파일이 풀립니다.

### 코드 작성 예시

```cpp
// stegzip.cpp
// Build: g++ -std=c++17 -O2 -o stegzip stegzip.cpp
// Usage:
//  Embed:  ./stegzip embed <image-file> <zip-file> <out-file>
//  Extract:./stegzip extract <combined-file> <out-zip-file>
//
// Note: This program appends ZIP bytes to an image (embed) and locates ZIP
// signature PK\x03\x04 to extract (extract). For very large files you may
// want a streaming search; this simple version loads into RAM.

// * 빌드예시 g++ -std=c++17 -O2 -o stegzip stegzip.cpp
// * 생성예시 ./stegzip embed picture.png secret.zip combined.png
// * 추출예시 ./stegzip extract combined.png recovered.zip

#include <bits/stdc++.h>
using namespace std;

static const array<unsigned char,4> ZIP_SIG = {0x50, 0x4B, 0x03, 0x04};

bool file_exists(const string &path){
    ifstream ifs(path, ios::binary);
    return ifs.good();
}

int embed_files(const string &image, const string &zip, const string &out){
    if(!file_exists(image) || !file_exists(zip)){
        cerr << "Error: input files missing.\n";
        return 1;
    }

    // Read image
    ifstream ifs_image(image, ios::binary);
    if(!ifs_image){ cerr << "Error: could not open image.\n"; return 1; }
    vector<char> img_data((istreambuf_iterator<char>(ifs_image)), istreambuf_iterator<char>());
    ifs_image.close();

    // Read zip
    ifstream ifs_zip(zip, ios::binary);
    if(!ifs_zip){ cerr << "Error: could not open zip.\n"; return 1; }
    vector<char> zip_data((istreambuf_iterator<char>(ifs_zip)), istreambuf_iterator<char>());
    ifs_zip.close();

    // Write combined
    ofstream ofs(out, ios::binary);
    if(!ofs){ cerr << "Error: could not create output file.\n"; return 1; }
    ofs.write(img_data.data(), img_data.size());
    ofs.write(zip_data.data(), zip_data.size());
    ofs.close();

    cout << "Created " << out << " (image + zip appended).\n";
    return 0;
}

size_t find_zip_signature(const vector<unsigned char> &data){
    // Naive search for PK\x03\x04
    if(data.size() < ZIP_SIG.size()) return string::npos;
    for(size_t i=0;i+ZIP_SIG.size()<=data.size();++i){
        if(data[i] == ZIP_SIG[0] &&
           data[i+1] == ZIP_SIG[1] &&
           data[i+2] == ZIP_SIG[2] &&
           data[i+3] == ZIP_SIG[3]) {
               return i;
           }
    }
    return string::npos;
}

int extract_zip(const string &combined, const string &outzip){
    if(!file_exists(combined)){
        cerr << "Error: combined file not found.\n";
        return 1;
    }

    ifstream ifs(combined, ios::binary);
    if(!ifs){ cerr << "Error: cannot open combined file.\n"; return 1; }
    vector<unsigned char> all((istreambuf_iterator<char>(ifs)), istreambuf_iterator<char>());
    ifs.close();

    size_t pos = find_zip_signature(all);
    if(pos == string::npos){
        cerr << "Error: ZIP signature (PK\\x03\\x04) not found in file.\n";
        return 2;
    }

    // Write from pos to end as zip
    ofstream ofs(outzip, ios::binary);
    if(!ofs){ cerr << "Error: cannot create output zip.\n"; return 1; }
    ofs.write(reinterpret_cast<const char*>(all.data()+pos), all.size()-pos);
    ofs.close();

    cout << "Extracted ZIP to " << outzip << " (offset " << pos << ").\n";
    return 0;
}

int main(int argc, char** argv){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if(argc < 2){
        cerr << "Usage:\n  Embed:   " << argv[0] << " embed <image> <zip> <out>\n"
             << "  Extract: " << argv[0] << " extract <combined> <out-zip>\n";
        return 1;
    }

    string cmd = argv[1];
    try{
        if(cmd == "embed"){
            if(argc != 5){ cerr << "embed requires 3 args\n"; return 1; }
            return embed_files(argv[2], argv[3], argv[4]);
        } else if(cmd == "extract"){
            if(argc != 4){ cerr << "extract requires 2 args\n"; return 1; }
            return extract_zip(argv[2], argv[3]);
        } else {
            cerr << "Unknown command: " << cmd << "\n";
            return 1;
        }
    } catch(const exception &e){
        cerr << "Exception: " << e.what() << "\n";
        return 1;
    }
}
```
