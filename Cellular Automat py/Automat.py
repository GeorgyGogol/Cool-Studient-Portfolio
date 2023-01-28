PROJECT_Name =			"Automat"
PROJECT_Author =		"Che_Gogol"
PROJECT_Date_start =	"03.02.2022 21:54"
PROJECT_Version =		"Alfa 1 w1"
PROJECT_Date = 			"03.02.2022"

width = 64
height = 32

class Field():
	def __init__(self, width, height):
		self.__wid = width
		self.__hei = height
		self.__cells = []
		self.__cellsNew = []
		for y in range(height + 1):
			self.__cells.append([])
			self.__cellsNew.append([])
			for x in range(width + 1):
				self.__cells[y].append(0)
				self.__cellsNew[y].append(0)
	def __str__(self):
		out = ''
		for y in range(self.__hei):
			for x in range(self.__wid):
				out += str(self.__cells[y][x])
			out += '\n'
		return out
	def getCell(self, x, y):
		return self.__cells[y][x]
	def setAlifeCells(self, n, posits):
		for i in range(n):
			x = posits[i * 2]
			y = posits[i * 2 + 1]
			self.__cells[y][x] = 1
	def update(self):
		neigh = 0
		for y in range(self.__hei + 1):
			for x in range(self.__wid + 1):
				neigh = self.__getNeighbors(x, y)
				if neigh == 3:
					self.__cellsNew[y][x] = 1
				elif neigh == 2:
					self.__cellsNew[y][x] = self.__cells[y][x]
				else:
					self.__cellsNew[y][x] = 0
			#print()
		for y in range(self.__hei + 1):
			for x in range(self.__wid + 1):
				self.__cells[y][x] = self.__cellsNew[y][x]
	def __getNeighbors(self, pos_x, pos_y):
		start_x = pos_x - 1
		if start_x < 0: start_x = 0
		
		end_x = pos_x + 1 + 1
		if end_x > self.__wid: end_x = self.__wid
		
		start_y = pos_y - 1
		if start_y < 0: start_y = 0
		
		end_y = pos_y + 1 + 1
		if end_y > self.__hei: end_y = self.__hei
		
		n = 0
		#print("at x{0}.y{1}:".format(pos_x, pos_y))
		for y in range(start_y, end_y):
			for x in range(start_x, end_x):
				if y == pos_y and x == pos_x: continue
				if self.__cells[y][x] == 1: n += 1
				#print("  in {2}.{3} n = {4}".format(pos_x, pos_y, x, y, n))
	
		#print("x{3}->{4} y{5}->{6}, neigh = {2}".format(0, 0, n, start_x, end_x - 1, start_y, end_y - 1))
		#print()
		return n

if __name__ == '__main__':
	
	f = Field(40, 5)
	f.setAlifeCells(5, [0, 3, 1, 1, 1, 3, 2, 2, 2, 3])
	print(f); print()
	
	
	c = None
	while not c:
		f.update()
		print(f); #print()
		c = input()
	

	
	
	
	
