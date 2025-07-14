import bpy

## Declaration ====================================================================

### Print Declaration

def print(*args):
    for area in bpy.context.screen.areas:
        if area.type == 'CONSOLE':
            context_override = {
                'area': area,
                'space_data': area.spaces.active,
                'region': area.regions[-1],
                'window': bpy.context.window,
                'screen': bpy.context.screen
            }
            text = " ".join(str(arg) for arg in args)
            with bpy.context.temp_override(**context_override):
                for line in text.split("\n"):
                    bpy.ops.console.scrollback_append(text=line, type='OUTPUT')


### Dictionary Declaration

objName = "target"

vxIter = iter("""
sd xc
qw er
""".split())

vxDict = {}

while True:
    try:
        vxDict[vx[0]] = vx[1]
        vxDict[vx[1]] = vx[0]
    except StopIteration:
        break


### Function Declaration

def printDict(vxDict):
    for i in vxDict.items():
        print(i)
    return

def vertexRelocate(objName, vxDict):
    return


## Working Area ===================================================================