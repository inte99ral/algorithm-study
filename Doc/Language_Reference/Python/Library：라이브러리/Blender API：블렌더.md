# Blender API：블렌더

## 목차

- [Blender API：블렌더](#blender-api블렌더)
  - [목차](#목차)
  - [스크립트 창 띄우기](#스크립트-창-띄우기)
  - [콘솔창에 Hello, world 출력하기](#콘솔창에-hello-world-출력하기)
  - [버텍스 그룹 바꾸기 자동화](#버텍스-그룹-바꾸기-자동화)
  - [buf 데이터 읽기](#buf-데이터-읽기)
    - [.md 로 읽기](#md-로-읽기)
    - [.xlsx 로 읽기](#xlsx-로-읽기)
  - [buf outline 데이터 조정](#buf-outline-데이터-조정)
    - [.buf 파일 직접 조작](#buf-파일-직접-조작)
    - [.xlsx 파일로 .buf 파일 조작](#xlsx-파일로-buf-파일-조작)

## 스크립트 창 띄우기

- 상단 메뉴의 `Scripting` 을 누르면 Text Editor 창이 뜹니다.

- Text Editor 상단 탭에서 `+새로운`(New) 버튼을 클릭해서 텍스트를 새로 작성하거나, `열기` 로 불러올 수 있습니다.

- Text Editor 상단 탭에서 `▶` 버튼 또는 `alt + p` 단축키 입력시 코드를 실행합니다.

&nbsp; 예를 들어, 다음의 코드를 작성하고 구동하면 큐브가 생성됩니다.

```py
import bpy

# 예시: Cube 생성
bpy.ops.mesh.primitive_cube_add(size=2, location=(0, 0, 0))
```

## 콘솔창에 Hello, world 출력하기

&nbsp; print 는 파이썬 인터프리터 콘솔창 출력 함수기 때문에 블렌더의 콘솔창에는 출력되지 않습니다.

&nbsp; 따라서 파이썬 콘솔창의 출력값을 블렌더 콘솔창으로 넘겨주는 함수를 만들고 print 함수에 오버라이드 해야합니다.

&nbsp; Blender의 연산자(Operator) 시스템은 UI 컨텍스트에 강하게 종속되기 때문에 print 함수를 오버라이드 할 때, 컨텍스트 오버라이딩이 필요합니다.

&nbsp; 뷰포트연산 "bpy.ops.mesh.primitive_cube_add()" 명령을 내리기 전에 당연히 "3D 뷰포트"가 활성화가 되어있어야 하듯, 콘솔관련연산 "bpy.ops.console.scrollback_append()" 는 콘솔 영역 컨텍스트로 콘솔 영역의 물리적 존재와 활성 상태가 검증되야 합니다. 검증되어야 하는 컨텍스트들은 다음과 같습니다.

- area: 콘솔 영역의 물리적 위치/크기 정보
- space_data: 콘솔의 기능 설정 (스크롤 위치, 이력 저장 방식 등)
- region: 텍스트 렌더링을 위한 실제 드로잉 영역
- window: 실제 시스템 콘솔창 내역
- screen: 보여지는 콘솔창 내역

&nbsp; 따라서 다음의 코드로 콘솔창에 문장을 출력할 수 있습니다.

```py
import sys
import bpy

_print_buffer = ""
_builtin_print = print
def print(*args, sep=' ', end='\n', file=None, flush=False):
    global _print_buffer
    text = sep.join(str(arg) for arg in args) + end

    _print_buffer += text

    # * \n
    while "\n" in _print_buffer:
        line, _print_buffer = _print_buffer.split("\n", 1)
        for area in bpy.context.screen.areas:
            if area.type == 'CONSOLE':
                context_override = {
                    'area': area,
                    'space_data': area.spaces.active,
                    'region': area.regions[-1],
                    'window': bpy.context.window,
                    'screen': bpy.context.screen
                }
                with bpy.context.temp_override(**context_override):
                    bpy.ops.console.scrollback_append(text=line, type='OUTPUT')

    # * flush
    if flush and _print_buffer:
        for area in bpy.context.screen.areas:
            if area.type == 'CONSOLE':
                context_override = {
                    'area': area,
                    'space_data': area.spaces.active,
                    'region': area.regions[-1],
                    'window': bpy.context.window,
                    'screen': bpy.context.screen
                }
                with bpy.context.temp_override(**context_override):
                    bpy.ops.console.scrollback_append(text=_print_buffer, type='OUTPUT')
        _print_buffer = ""

print(sys.version, end=" ")
print("log00", end= " ")
print("log01", end= " ")
print("log02")
```

&nbsp; 또는 시스템 출력 스트림 객체에 오버라이드하여 블렌더 콘솔에 적용하게 시키는 방법도 있습니다. 다음과 같이 적용됩니다.

```py
import sys
import bpy

class ConsoleRedirect:
    def write(self, text):
        sys.__stdout__.write(text)  # 시스템 콘솔 출력 유지
        if text.strip():
            for area in bpy.context.screen.areas:
                if area.type == 'CONSOLE':
                    with bpy.context.temp_override(area=area):
                        bpy.ops.console.scrollback_append(text=text, type='OUTPUT')

sys.stdout = ConsoleRedirect()
print("hello, world")  # 자동 리다이렉트
```

## 버텍스 그룹 바꾸기 자동화

- 다음의 코드를 통하여 버텍스 그룹을 바꿀 수 있습니다.

```py
import bpy

## Declaration ====================================================================

### Print

_print_buffer = ""
_builtin_print = print
def print(*args, sep=' ', end='\n', file=None, flush=False):
    global _print_buffer
    text = sep.join(str(arg) for arg in args) + end

    _print_buffer += text

    # * \n
    while "\n" in _print_buffer:
        line, _print_buffer = _print_buffer.split("\n", 1)
        for area in bpy.context.screen.areas:
            if area.type == 'CONSOLE':
                context_override = {
                    'area': area,
                    'space_data': area.spaces.active,
                    'region': area.regions[-1],
                    'window': bpy.context.window,
                    'screen': bpy.context.screen
                }
                with bpy.context.temp_override(**context_override):
                    bpy.ops.console.scrollback_append(text=line, type='OUTPUT')

    # * flush
    if flush and _print_buffer:
        for area in bpy.context.screen.areas:
            if area.type == 'CONSOLE':
                context_override = {
                    'area': area,
                    'space_data': area.spaces.active,
                    'region': area.regions[-1],
                    'window': bpy.context.window,
                    'screen': bpy.context.screen
                }
                with bpy.context.temp_override(**context_override):
                    bpy.ops.console.scrollback_append(text=_print_buffer, type='OUTPUT')
        _print_buffer = ""


### vertexVolatilize

def vertexVolatilize(objName):
    obj = bpy.data.objects.get(objName)

    if obj is None or obj.type != 'MESH':
        print(f"[ERROR] Mesh object '{objName}' not found.")
        return

    obj.vertex_groups.clear()
    return


### vertexRelocate

def vertexRelocate(objName, gMap):

    # * Object Name Check

    obj = bpy.data.objects.get(objName)
    if obj is None or obj.type != 'MESH':
        print(f"[ERROR] Mesh object '{objName}' not found.")
        return

    # * Mode Check

    modeMap = {
        "OBJECT": "OBJECT",
        "EDIT_MESH": "EDIT",
        "EDIT_ARMATURE": "EDIT",
        "EDIT_CURVE": "EDIT",
        "POSE": "POSE"
    }

    prevMode = modeMap[bpy.context.mode]
    if prevMode != 'OBJECT':
        bpy.ops.object.mode_set(mode='OBJECT')

    # * Vertex Group New

    for name in ((set(gMap.keys()) | set(gMap.values())) - ({vg.name for vg in obj.vertex_groups})):
        obj.vertex_groups.new(name=name)

    # * Vertex Group Swap

    for v in obj.data.vertices:
        visited = set()

        # * copy
        groups = [(g.group, g.weight) for g in v.groups]
        for prevIndex, prevWeight in groups:
            prevName = obj.vertex_groups[prevIndex].name

            if prevName not in gMap:
                continue

            nextName = gMap[prevName]

            if (prevName in visited) or (nextName in visited):
                continue

            try:
                nextWeight = obj.vertex_groups[nextName].weight(v.index)
                obj.vertex_groups[nextName].add([v.index], prevWeight, 'REPLACE')
                obj.vertex_groups[prevName].add([v.index], nextWeight, 'REPLACE')
            except RuntimeError:
                obj.vertex_groups[nextName].add([v.index], prevWeight, 'REPLACE')
                obj.vertex_groups[prevName].remove([v.index])

            visited.add(prevName)
            visited.add(nextName)


    # * Mode Restore
    bpy.ops.object.mode_set(mode=prevMode)
    return

## Working Area ===================================================================

objName = "target"

gMap = {k: v for line in iter("""
_L_ _R_
0 0
4 1
38 33
39 34
40 35
41 36
42 37
58 43
59 44
60 45
61 46
62 47
63 48
64 49
65 50
66 51
67 52
68 53
69 54
70 55
71 56
72 57
85 84
""".strip().splitlines()) if len(g := line.split()) == 2 and line[0] != '_' for k, v in [(g[0], g[1]), (g[1], g[0])]}

vertexRelocate(objName, gMap)
# vertexVolatilize(objName)
```

## buf 데이터 읽기

.buf 헥사 파일은 일반적인 텍스처 코디네이트 + 외곽선 정보 구성과 유사한 데이터를 가지고 있습니다.

| offset | 바이트 0 | 바이트 1 | 바이트 2                | 바이트 3          | 바이트 4–7            |
| ------ | -------- | -------- | ----------------------- | ----------------- | --------------------- |
| 설명   | U 좌표   | V 좌표   | 정규화된 노멀 또는 알파 | Outline thickness | 패딩 또는 예비 데이터 |

8 테이블 외에 20 테이블로 확장된 형태로 더 많은 데이터(UV 대신 여러 UV 레이어, 마스크 값, 기타 파라미터 등) 를 가지는 경우도 있습니다.

예를 들어서 게임 개발시 Hair, Head 파츠일 경우 stride 값은 8로, 그 외 본체 파츠에는 stride 값으로 20 을 사용하는 경우가 있습니다.

### .md 로 읽기

&nbsp; 아래의 코드를 작성하고 파워쉘에서 `python 『PYTHON_FILE_NAME』.py 『BUF_FILE_NAME』.buf --stride 『STRIDE_8_OR_20』 --output 『MD_FILE_NAME』.md` 명령어로 구동시킬 수 있습니다.

```python
# convertBufIntoMd.py
## Command : python 『PYTHON_FILE_NAME』.py 『BUF_FILE_NAME』.buf --stride 『STRIDE_8_OR_20』 --output 『MD_FILE_NAME』.md
import argparse
import os

def main():
    parser = argparse.ArgumentParser(description="Parse texcoord.buf and export stride data to Markdown table with row numbers")
    parser.add_argument("texcoord_file", type=str, help="Input texcoord.buf file name")
    parser.add_argument("--stride", type=int, required=True, help="Stride value")
    parser.add_argument("--output", type=str, default="buf_output.md", help="Output markdown.md file name")
    args = parser.parse_args()

    if not os.path.exists(args.texcoord_file):
        print("wrong texcoord.buf file name")
        return

    with open(args.texcoord_file, "rb") as f:
        data = bytearray(f.read())

    with open(args.output, "w", encoding="utf-8") as md:
        header = ["Row"] + [f"Byte {i+1}" for i in range(args.stride)]
        md.write("| " + " | ".join(header) + " |\n")
        md.write("|" + "|".join([":---:" for _ in range(len(header))]) + "|\n")

        rowNum = 1
        for i in range(0, len(data), args.stride):
            rowData = data[i : i + args.stride]
            row = [f"Row {rowNum}"] + [str(b) for b in rowData]
            row += [""] * (args.stride - len(rowData))
            md.write("| " + " | ".join(row) + " |\n")
            rowNum += 1

    print(f"Save as markdown .md completed: {args.output}")

if __name__ == "__main__":
    main()

```

### .xlsx 로 읽기

&nbsp; 엑셀로 저장하기 위해선 openpyxl 의존성을 설치해야 합니다.

```python
pip install openpyxl
```

&nbsp; 다음의 코드로 엑셀파일로 저장할 수 있습니다.

```python
# convertBufIntoXlsx.py
## Command : python 『PYTHON_FILE_NAME』.py 『BUF_FILE_NAME』.buf --stride 『STRIDE_8_OR_20』 --output 『EXCEL_FILE_NAME』.xlsx
import argparse
import os
from openpyxl import Workbook

def main():
    parser = argparse.ArgumentParser(description="Parse texcoord.buf and export stride data to Excel")
    parser.add_argument("texcoord_file", type=str, help="Input input.buf name")
    parser.add_argument("--stride", type=int, required=True, help="Stride 값")
    parser.add_argument("--output", type=str, default="output.xlsx", help="Input output.xlsx name")
    args = parser.parse_args()

    if not os.path.exists(args.texcoord_file):
        print("Wrong texcoord .buf file name")
        return

    with open(args.texcoord_file, "rb") as f:
        data = bytearray(f.read())

    wb = Workbook()
    ws = wb.active
    ws.title = "BUF Data"

    # Header row
    header = ["Row"] + [f"Byte {i+1}" for i in range(args.stride)]
    ws.append(header)

    # Add each stride row
    rowNum = 1
    for i in range(0, len(data), args.stride):
        rowData = data[i : i + args.stride]
        row = [f"Row {rowNum}"] + [str(b) for b in rowData]
        row += [""] * (args.stride - len(rowData))
        ws.append(row)
        rowNum += 1

    wb.save(args.output)
    print(f"Save as excel .xlsx completed: {args.output}")

if __name__ == "__main__":
    main()
```

## buf outline 데이터 조정

### .buf 파일 직접 조작

.buf 헥사 파일은 일반적인 텍스처 코디네이트 + 외곽선 정보 구성과 유사한 데이터를 가지고 있습니다.

| offset | 바이트 0 | 바이트 1 | 바이트 2                | 바이트 3          | 바이트 4–7            |
| ------ | -------- | -------- | ----------------------- | ----------------- | --------------------- |
| 설명   | U 좌표   | V 좌표   | 정규화된 노멀 또는 알파 | Outline thickness | 패딩 또는 예비 데이터 |

8 테이블 외에 20 테이블로 확장된 형태로 더 많은 데이터(UV 대신 여러 UV 레이어, 마스크 값, 기타 파라미터 등) 를 가지는 경우도 있습니다.

```python
# https://arca.live/b/genshinskinmode/93106906
# set_outlines.py 파일 만들고 python set_outlines.py March7thHairTexcoord.buf --stride 8 --thickness 60 이런식으로 사용하면 됨
# Hair, Head 에 사용할떄는 stride 8, 그 외엔 20

import argparse
import os

def main():
    parser = argparse.ArgumentParser(description="Set outline thickness for a specified Texcoord.buf file")
    parser.add_argument("texcoord_file", type=str, help="texcoord.buf 파일 이름")
    parser.add_argument("--stride", type=int, help="Stride 값")
    parser.add_argument("--thickness", type=int, default=60, help="Thickness of outline (0 - no outline, 255 - maximum outline)")
    args = parser.parse_args()

    if not os.path.exists(args.texcoord_file):
        print("Wrong texcoord .buf file name")
        return

    with open(args.texcoord_file, "rb+") as f:
        data = bytearray(f.read())
        i = 0
        while i < len(data):
            data[i+3] = args.thickness
            i += args.stride

        f.seek(0)
        f.write(data)
        f.truncate()

if __name__ == "__main__":
    main()
```

### .xlsx 파일로 .buf 파일 조작

```python
# convertXlsxIntoBuf.py
## Command : python 『PYTHON_FILE_NAME』.py EXCEL_FILE_NAME』.xlsx --output 『BUF_FILE_NAME』.buf

import argparse
import os
from openpyxl import load_workbook

def main():
    parser = argparse.ArgumentParser(description="Convert Excel file (from convertBufIntoXlsx.py) back into .buf binary format")
    parser.add_argument("xlsx_file", type=str, help="Input Excel file")
    parser.add_argument("--output", type=str, default="output.buf", help="Output .buf file name")
    args = parser.parse_args()

    if not os.path.exists(args.xlsx_file):
        print("wrong excel .xlsx file name")
        return

    wb = load_workbook(args.xlsx_file)
    ws = wb.active

    data_bytes = bytearray()

    for row in ws.iter_rows(min_row=2, min_col=2):  # Skip header row and header column
        for cell in row:
            if cell.value is None:
                continue
            try:
                byte_value = int(cell.value)
                if not 0 <= byte_value <= 255:
                    raise ValueError
                data_bytes.append(byte_value)
            except ValueError:
                print(f"Invalid byte value: {cell.value}")
                return

    with open(args.output, "wb") as f:
        f.write(data_bytes)

    print(f"Save as texcoord .buf file completed: {args.output}")

if __name__ == "__main__":
    main()
```
