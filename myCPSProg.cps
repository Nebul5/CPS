Polygon myPoly 5 20
Polygon myTrian 3 40
Polygon mySquare 4 30
Sphere mySphere 10 1.0 0.6 0.2 -0.6 0.5 -0.6
Sphere mySphere2 6 0.2 0.7 0.5 -1.2 1.8 1.2
move 100 100
draw myPoly
draw scale 10 10 myTrian end end
move 300 300
draw rotate 10 scale 5 5 mySphere end
move -200 -200
draw rotate 40 scale 4 4 mySphere2
