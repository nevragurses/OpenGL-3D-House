OPENGL ve GLUT kütüphaneleri Ubuntu üzerine kurulmuştur ve kod Linux üzerinde yazılıp derlenmiştir.

Kurulum için komutlar:
- sudo apt-get update
- sudo apt-get install libglu1-mesa-dev freeglut3-dev mesa-common-dev

Kodu derlemek ve çalıştırmak için gerekli komutlar:
- g++ 3DHome.cpp -o 3DHome -lglut -lGLU -lGL
- ./3DHome

Çalışan kodu gösteren video linki:
https://www.youtube.com/watch?v=fKHvzFkqaR8