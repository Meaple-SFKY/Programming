import torch

path = 'E:/code/yolov5-master/yolov5_models'

model = torch.hub.load(path, 'best', pretrained=True, source = 'local')


# Image
img = 'data/images/a2.jpg'

# Inference
results = model(img)
results.print()  # or .show(), .save()


# import torch
#
# # Model
# model = torch.hub.load('./ultralytics/yolov5', 'yolov5s')
#
# # Image
# img = 'https://ultralytics.com/images/zidane.jpg'
#
# # Inference
# results = model(img)
# results.print()  # or .show(), .save()