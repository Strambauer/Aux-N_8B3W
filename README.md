# Aux-N_8B3W
ISOBUS Aux-N input panel with 8 buttons and 3 rocker

## Setup the Enviroment
It is recommanded to use a Ubuntu installation with Version 16. Version 18 is not recomanded becaus of a to new verson of xerces-c supplayed by the package manager. With the new Version vt2iso will not build.
Another library you need to build vt2iso is boost.

You can get this two librarys by apt-get them

	sudo apt-get install libboost-all-dev libxerces-c2-dev 

After installing the two libs you can build vt2ios

	cd IsoAgLib/tools/vt2iso/cmake
	cmake .
	make

Now vt2iso should be ready to use.

## Create the objectpool from xml-Files

To create the folowing call is needed from the projects home diroctory

	IsoAgLib/tools/vt2iso/cmake/vt2iso project_data/VT/Aux-N_8B3W.vtp -o=project_data/object_pool/

## Create the project files 

	cd project_data/project_config/

	../../IsoAgLib/tools/project_generation/conf2build.sh conf_Aux-N_8B3W
