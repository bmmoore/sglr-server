all :
	make -C aterm/src/
	make -C error-support/src/
	make -C pt-support/src/
	make -C sglr/src/
	make -C sglr-server/src/
clean :
	make -C aterm/src/ clean
	make -C error-support/src/ clean
	make -C pt-support/src/ clean
	make -C sglr/src/ clean
	make -C sglr-server/src/ clean
