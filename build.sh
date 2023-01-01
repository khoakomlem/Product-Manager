echo "Compiling Util.cpp" &&
C:/MinGW/bin/g++.exe -c src/Util/Util.cpp -o objects/Util.o &&
echo "Compiling Sat2d.cpp" &&
C:/MinGW/bin/g++.exe -c src/Sat2d/Sat2d.cpp -o objects/Sat2d.o &&
echo "Compiling Element.cpp" &&
C:/MinGW/bin/g++.exe -c src/Element/Element.cpp -o objects/Element.o &&
echo "Compiling Model.cpp" &&
C:/MinGW/bin/g++.exe -c src/Model/Model.cpp -o objects/Model.o &&
echo "Compiling main.cpp" &&
C:/MinGW/bin/g++.exe -c src/main.cpp -o objects/main.o &&
echo "Linking each others" &&
C:/MinGW/bin/g++.exe objects/Util.o objects/Sat2d.o objects/Element.o objects/Model.o objects/main.o -o bin/BachHoaXanh.exe -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32
echo "Build success bin/BachHoaXanh.exe!"
