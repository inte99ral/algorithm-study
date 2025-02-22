import base64

def imgToBase64(imgPath):
  with open(imgPath, 'rb') as img_file:
    encoded_str = base64.b64encode(img_file.read()).decode('ascii')
  
  return encoded_str

imgPath = "path/to/your/image.jpg"
base64Str = imgToBase64(imgPath)

print("Base64 인코딩된 이미지:")
print(base64Str)