package BJ.Silver.S3;
// https://www.acmicpc.net/problem/1244

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BJ_1244_스위치 {
    public static void main(String[] args) throws Exception{
        System.setIn(new FileInputStream("input.txt"));
        BufferedReader br;
        StringTokenizer st;

        br = new BufferedReader(new InputStreamReader(System.in));
        int size = Integer.parseInt(br.readLine());
        boolean[] bArr = new boolean[size + 1];

        st = new StringTokenizer(br.readLine());
        for(int i = 1; i <= size; i++) bArr[i] = st.nextToken().charAt(0) == '1';

        int N = Integer.parseInt(br.readLine());
        for(int n = 0; n < N; n++){
            st = new StringTokenizer(br.readLine());
            if(st.nextToken().charAt(0) == '1'){
                int num = Integer.parseInt(st.nextToken());
                for(int i = 1; i*num <= size; i++) bArr[i*num] ^= true;
            }
            else{
                int num = Integer.parseInt(st.nextToken());
                bArr[num] = !bArr[num];
                for(int i = 1; i <= size; i++){
                    if(num - i < 1) break;
                    if(num + i > size) break;
                    if(bArr[num - i] != bArr[num + i]) break;
                    bArr[num - i] ^= true;
                    bArr[num + i] ^= true;
                }
            }
        }

        int count = 1;
        for(int i = 1; i <= size; i++){
            System.out.print(bArr[i]? 1 : 0);
            if(count++ >= 20){
                count = 1;
                System.out.println();
            }
            else System.out.print(' ');
        }
    }
}
