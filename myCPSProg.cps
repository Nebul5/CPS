Polygon myPoly 5 20
Polygon myTrian 3 40
Polygon mySquare 4 30
move 500 300
draw myPoly
scale 10 10
draw myPoly
rotate 45 0 0 1
draw myPoly
pop pop
scale 20 20
draw myTrian
pop
scale 25 25
draw myTrian
pop
scale 30 30
draw myTrian
pop
move 300 1000
rotate 45 0 0 1 scale 20 20
draw mySquare
pop
scale 40 40
draw mySquare 
pop pop pop pop
Sphere mySphere 10 1.0 0.6 0.2 -0.6 0.5 -0.6
Sphere mySphere2 10 0.2 0.7 0.5 -1.2 1.8 1.2
Sphere mySphere3 10 0.8 0.2 0.3 0.0 1.0 0.0
move 850 500
scale 30 30 rotate 100 1 0 1
draw mySphere3
pop pop pop
move 900 1200
scale 30 30
rotate 90 1 1 0
draw mySphere
pop pop pop
move 500 900
scale 35 35 rotate 60 1 0 0
draw mySphere2


