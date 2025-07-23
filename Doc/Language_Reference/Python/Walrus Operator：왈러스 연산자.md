# Walrus Operator：왈러스 연산자

## 예시

```python
objName = "obj-name"

# * Dictionary Comprehension & Walrus Operator
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
""".strip().splitlines()) if len(g := line.split()) == 2 for k, v in [(g[0], g[1]), (g[1], g[0])]}

vertexRelocate(objName, gMap)
```
