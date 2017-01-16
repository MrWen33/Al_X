from turtle import *

def linedraw(i1,x=50):
	if i1!=0:
		left(60)
		forward(x)
		linedraw(i1-1,x*0.5)
		right(180)
		forward(x)
		left(60)
		forward(x)
		linedraw(i1-1,x*0.5)
		right(180)
		forward(x)
		right(120)

def snowstyle(num,circ,size):
	for i in range(num):
		forward(size)
		linedraw(circ,size)
		right(180)
		forward(size)
		right(180)
		right(360/num)

setup(1920,1080,0,0)
speed(50)
pensize(5)
snowstyle(3,3,100)
pencolor("white")
pensize(3)
snowstyle(3,3,100)
done()