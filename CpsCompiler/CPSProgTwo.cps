Polygon p 5 30
Square sq 40
Rectangle r 50 30
Triangle t 30
Spacer sp 40 60
Circle c 50
Sphere sph1 50 1.0 0.6 0.2 -0.6 0.5 -0.6
Sphere sph2 50 0.3 0.8 0.6 -1.2 1.8 1.2
Sphere sph3 50 0.8 0.2 0.3 0.0 1.0 0.0
Vertical vert p sq r t c sp t p c end
Layered lay p sq r c end
Horizontal hor c sph1 c sph2 c sph3 p t p t end
move 100 900
draw vert
move 100 0
draw hor
pop pop move 400 400
draw lay


