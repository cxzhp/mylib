all: formatConvert.o scanImage.o distanceTransform 
	@echo "make distanceTransform"
.PHONY: all


thin: lib/scanImage.cpp lib/formatConvert.cpp app/thin.cpp
	g++ scanImage.o formatConvert.o -o thin app/thin.cpp  -I /usr/local/include/opencv -L /usr/local/lib/ -lopencv_highgui -lopencv_core -lopencv_imgcodecs -lopencv_imgproc 
	@echo "usage: ./thin  data/abcd.jpeg"

distanceTransform: lib/scanImage.cpp lib/formatConvert.cpp app/distanceTransform.cpp
	g++ scanImage.o formatConvert.o -o distanceTransform app/distanceTransform.cpp  -I /usr/local/include/opencv -L /usr/local/lib/ -lopencv_highgui -lopencv_core -lopencv_imgcodecs -lopencv_imgproc 
	@echo "usage: ./distanceTransform  data/cards.png"

scanImage.o: lib/scanImage.cpp lib/formatConvert.cpp
	 g++ -c lib/scanImage.cpp

formatConvert.o: lib/formatConvert.cpp
	 g++ -c lib/formatConvert.cpp


.PHONY: clean
clean:
	-rm formatConvert.o scanImage.o distanceTransform
