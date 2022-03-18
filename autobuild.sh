set -X
rm -rf `pwd`/build/*
cd `pwd`/build &&
	cmake .. &&
	make
