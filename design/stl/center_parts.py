import bpy
import os
from pathlib import Path
import glob
import numpy as np
from subprocess import call



for file in glob.glob("*.stl"):
	bpy.ops.object.select_all(action='SELECT')
	bpy.ops.object.delete()
	print("Creating centered copy of: ", file)
	bpy.ops.import_mesh.stl(filepath=file)
	objs = bpy.data.objects
	for obj in objs:
		print("Object: {}".format(obj.name))
	new_obj = bpy.context.scene.objects.active
	bpy.ops.object.origin_set(type='ORIGIN_CENTER_OF_MASS')
	new_obj.location = [0., 0., 0.]
	#bpy.context.space_data.context = 'SCENE'
	#bpy.ops.script.python_file_run(filepath="/home/pierre/workspace/blensor/build/bin/2.79/scrpits/presents/units_length/centimeters.py")
	new_filename = "".join([os.path.splitext(file)[0], "_centered.stl"])
	bpy.ops.export_mesh.stl(filepath=new_filename)
	call(["mv",file, file + ".old"])

