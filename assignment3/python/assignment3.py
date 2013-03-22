'''

Assignment 3 -- DYPL

Authors : stro0335, 

'''

dict = input("Please enter dictionary path : ")
myInput = input("Please enter input path : ")

class   Dictionary:
    def __init__(self, path):
        self._sentence = ""
        self._dict = open(path, "r")
        self._rules = {}
        self._rulesByletter = {}
        self._dictMap = {}

    def __del__(self):
        self._dict.close()
        
    def init(self):
        self._rules['0'] = "Ee";
        self._rules['1'] = "JNQjnq";
        self._rules['2'] = "RWXrwx";
        self._rules['3'] = "DSYdsy";
        self._rules['4'] = "FTft";
        self._rules['5'] = "AMam";
        self._rules['6'] = "CIVciv";
        self._rules['7'] = "BKUbku";
        self._rules['8'] = "LOPlop";
        self._rules['9'] = "GHZghz";

        self._rulesByletter['a'] = '5';
        self._rulesByletter['b'] = '7';
        self._rulesByletter['c'] = '6';
        self._rulesByletter['d'] = '3';
        self._rulesByletter['e'] = '0';
        self._rulesByletter['f'] = '4';
        self._rulesByletter['g'] = '9';
        self._rulesByletter['h'] = '9';
        self._rulesByletter['i'] = '6';
        self._rulesByletter['j'] = '1';
        self._rulesByletter['k'] = '7';
        self._rulesByletter['l'] = '8';
        self._rulesByletter['m'] = '5';
        self._rulesByletter['n'] = '1';
        self._rulesByletter['o'] = '8';
        self._rulesByletter['p'] = '8';
        self._rulesByletter['q'] = '1';
        self._rulesByletter['r'] = '2';
        self._rulesByletter['s'] = '3';
        self._rulesByletter['t'] = '4';
        self._rulesByletter['u'] = '7';
        self._rulesByletter['v'] = '6';
        self._rulesByletter['w'] = '2';
        self._rulesByletter['x'] = '2';
        self._rulesByletter['y'] = '3';
        self._rulesByletter['z'] = '9';

        self._rulesByletter['A'] = '5';
        self._rulesByletter['B'] = '7';
        self._rulesByletter['C'] = '6';
        self._rulesByletter['D'] = '3';
        self._rulesByletter['E'] = '0';
        self._rulesByletter['F'] = '4';
        self._rulesByletter['G'] = '9';
        self._rulesByletter['H'] = '9';
        self._rulesByletter['I'] = '6';
        self._rulesByletter['J'] = '1';
        self._rulesByletter['K'] = '7';
        self._rulesByletter['L'] = '8';
        self._rulesByletter['M'] = '5';
        self._rulesByletter['N'] = '1';
        self._rulesByletter['O'] = '8';
        self._rulesByletter['P'] = '8';
        self._rulesByletter['Q'] = '1';
        self._rulesByletter['R'] = '2';
        self._rulesByletter['S'] = '3';
        self._rulesByletter['T'] = '4';
        self._rulesByletter['U'] = '7';
        self._rulesByletter['V'] = '6';
        self._rulesByletter['W'] = '2';
        self._rulesByletter['X'] = '2';
        self._rulesByletter['Y'] = '3';
        self._rulesByletter['Z'] = '9';

        for i in range(10):
            self._dictMap[str(i)] = []

        for line in self._dict.readlines():
            key = self._rulesByletter[line[0]]
            self._dictMap[key].append(line.replace('\n', ''))

    def findOccurences(self, number, rawNum):
        for i in self._dictMap[number[0]]:
            if len(i) <= len(number):
                ws = self.isWordMatches(number, i)
                if (ws == 0 or ws == 1):
                    self._sentence += " "
                    self._sentence += i
                    if (ws == 1):
                        self.showSentence(rawNum)
                    if (number[len(i):] != ""):
                        self.findOccurences(number[len(i):], rawNum)
        self._sentence = ""
        
    def isWordMatches(self, num, sample):
        i = 0
        while (i != len(sample) and i != len(num)):
            if ((self.isCharInRule(num[i], sample[i]) is True)):
                i += 1
            else:
                break
        if (i == len(sample)):
            if (i != len(num)):
                return 0
            return 1
        return -1
    
    def isCharInRule(self, num, sample):
        pos = self._rules[num].find(sample)
        if (pos != -1):
            return True
        return False

    def showSentence(self, rawNum):
        print(rawNum + ":" + self._sentence)
        self._sentence = ""


class   FileReader:

    def __init__(self, dict, input):
        self._dict = Dictionary(dict)
        self._input = myInput
        self.init()
        self._inputFile = open(input, "r")
            
    def __del__(self):
        self._inputFile.close()

    def init(self):
        self._dict.init()

    def launch(self):
        for line in self._inputFile.readlines():
            self._dict.findOccurences(line.replace('\n', ''), line.replace('\n', ''))

reader = FileReader(dict, myInput)

reader.launch()
reader.__del__()
