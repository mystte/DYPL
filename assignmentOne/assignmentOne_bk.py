'''
 DYPL - Assignment one - Turtle Graphics
 authors : jogu3617 / pade4640

 ## Run
  $> java -jar /path/to/jython/home/jython.jar assignmentOne.py
'''

import JythonTranslater
import DYPL
import math
import re

class assignmentOne(JythonTranslater.Jtrans):
    def setDYPL(self, obj):
        self.dypl    = obj
        self.on      = True
        self.xpos    = 0
        self.ypos    = 0
        self.angle   = 0
        self.inLoop  = False
        self.regExps = [re.compile("\s*pen_down"),
                        re.compile("\s*pen_up"),
                        re.compile("\s*move_forward"),
                        re.compile("\s*move_backward"),
                        re.compile("\s*move\(\s*([0-9]+|[a-zA-Z]+)\s*([\+|\-|\*]?\s*([0-9]+|[a-zA-Z]+)\s*[\+|\-|\*]?\s*([0-9]+|[a-zA-Z]+))*\s*,\s*([0-9]+|[a-zA-Z]+)\s*([\+|\-|\*]?\s*([0-9]+|[a-zA-Z]+)\s*[\+|\-|\*]?\s*([0-9]+|[a-zA-Z]+))*\s*\)\s*"),
                        re.compile("\s*turn_cw\(\s*([0-9]+|[a-zA-Z]+)\s*([\+|\-|\*]?\s*([0-9]+|[a-zA-Z]+)\s*[\+|\-|\*]?\s*([0-9]+|[a-zA-Z]+))*\s*\)\s*"),
                        re.compile("\s*turn_ccw\(\s*([0-9]+|[a-zA-Z]+)\s*([\+|\-|\*]?\s*([0-9]+|[a-zA-Z]+)\s*[\+|\-|\*]?\s*([0-9]+|[a-zA-Z]+))*\s*\)\s*"),
                        re.compile("\s*put\(\s*([0-9]+|[a-zA-Z]+)\s*([\+|\-|\*]?\s*([0-9]+|[a-zA-Z]+)\s*[\+|\-|\*]?\s*([0-9]+|[a-zA-Z]+))*\s*,\s*([0-9]+|[a-zA-Z]+)\s*([\+|\-|\*]?\s*([0-9]+|[a-zA-Z]+)\s*[\+|\-|\*]?\s*([0-9]+|[a-zA-Z]+))*\s*,\s*([0-9]+|[a-zA-Z]+)\s*([\+|\-|\*]?\s*([0-9]+|[a-zA-Z]+)\s*[\+|\-|\*]?\s*([0-9]+|[a-zA-Z]+))*\s*\)\s*"),
                        re.compile("\s*for\s*[A-Za-z]+\s*=\s*[0-9]+\s*to\s*[0-9]+\s*do"),
                        re.compile("\s*end")]

    def actionPerformed(self, event):
        self.code             = self.dypl.getCode()
        self.instructions     = self.code.split('\n')
        self.loopInstructions = []
        self.loopParams       = []
        self.execc(self.instructions)

# STATEMENTS 
    def pen_down(self):
        self.on = True
    def pen_up(self):
        self.on = False

    def move_forward(self):
        if self.on == True:
            self.move(1, self.angle)
        else:
            print("Pen is UP!")
    def move_backward(self):
        if self.on == True:
            self.move(-1, self.angle)
        else:
            print("Pen is UP!")
    def move(self, step, angle):
        if self.on == True:
            self.angle += angle
            if self.angle >= 360:
                self.angle -= 360
            rad  = math.pi * (self.angle) / 180
            xend = int(round(self.xpos + (step * math.sin(rad))))
            yend = int(round(self.ypos - (step * math.cos(rad))))
            self.draw(self.xpos, self.ypos, xend, yend)
            self.xpos = xend
            self.ypos = yend
        else:
            print("Pen is UP!")

    def turn_cw(self, angle):
        self.angle += angle
        if self.angle >= 360:
            self.angle -= 360
    def turn_ccw(self, angle):
        self.angle -= angle
        if self.angle < 0:
            self.angle = self.angle * -1

    def put(self, xpos, ypos, angle):
        self.xpos  = xpos
        self.ypos  = ypos
        self.angle = angle
        
# EXECC FUNCTION: Executes instructions given as parameter
    def execc(self, instructions):
        for i in instructions:
            c = self.checkValidity(i)
            if c != -1:
                if c == 8:
                    self.inLoop = True
                    self.loopParams = i
                elif c == 9:
                    self.inLoop = False
                    self.execLoop(self.loopInstructions, self.loopParams)
                    self.loopInstructions = []
                    self.loopParams = ""
                elif self.inLoop == True:
                    self.loopInstructions.append(i)
                elif i[-1:] == ')':
                    eval("self." + i)
                else:
                    eval("self." + i + "()")

# EXEC LOOP FUNCTION: Executes instructions contained in the loop given as parameter
    def execLoop(self, loopInstructions, loopParams):
        params = list(re.sub(r'\s+', ' ', loopParams))
        if params[params.index('=') - 1] != ' ':
            params.insert(params.index('='), ' ')
        if params[params.index('=') + 1] != ' ':
            params.insert(params.index('=') + 1, ' ')
        paramStr = ''.join(params)
        paramTab = paramStr.split(' ')
        exec("global " + paramTab[1] + "\n" + paramTab[1] + " = " + paramTab[3] + "\nfor " + paramTab[1] + " in range(" + paramTab[5] + "):\n self.execc(loopInstructions)\n " + paramTab[1] + " += 1")

# DRAW FUNCTION: Draws the figure with the given coordinates.
    def draw(self, xstart, ystart, xend, yend):
        dx = abs(xend - xstart)
        dy = abs(yend - ystart)
        s = 0
        if (xend - xstart) > 0: 
            sx = 1
        else: sx = -1
        if (yend - ystart) > 0: 
            sy = 1
        else: sy = -1
        if dy > dx:
            s = 1
            xstart, ystart = ystart, xstart
            dx, dy = dy, dx
            sx, sy = sy, sx
        d = (2 * dy) - dx        
        for i in range(0, dx):
            if s: 
                self.dypl.setPixel(ystart, xstart)
            else: self.dypl.setPixel(xstart, ystart)
            while d >= 0:
                ystart = ystart + sy
                d = d - (2 * dx)
            xstart = xstart + sx
            d = d + (2 * dy)
            self.dypl.setPixel(xend, yend)

# CHECK VALIDITY FUNCTION: Checks if the given instruction matches with one contained in the regExps list.
    def checkValidity(self, instruction):
        i = 0
        for exp in self.regExps:
            if exp.search(instruction):
                return i
            i += 1
        return -1

app = DYPL(assignmentOne())
