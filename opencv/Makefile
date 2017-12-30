all:
	@echo "make distanceTransform"
.PHONY: all

distanceTransform: scanImage.o  app/distanceTransform.cpp
	g++ scanImage.o -o distanceTransform app/distanceTransform.cpp  -I /usr/local/include/opencv -L /usr/local/lib/ -lopencv_highgui -lopencv_core -lopencv_imgcodecs -lopencv_imgproc 
	@echo "usage: ./distanceTransform  data/cards.png"

scanImage.o: lib/scanImage.cpp
	 g++ -c lib/scanImage.cpp


.PHONY: clean
clean:
	-rm scanImage.o distanceTransform
