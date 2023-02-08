from datetime import datetime

ID = "{date}-a{author}-n{name}"
FilesPath = "D:\\{id}.{extension}"
Encoding = "Windows-1251"

class Information():
	__inf_params = ("name", "author", "dateCreate", "ver", "description", "shortDescription", "fullDescription", "verDate")
	def __init__(self, name, author, dateCreate = None, ver = None, description = None, shortDescription = None, fullDescription = None
				, verDate = None):
		if shortDescription and description: raise Exception("Create information error: its need only Description or shortDescription!")
		if not ver:
			ver = "Non_version"
		if not verDate:
			verDate = "Unspecified"
		
		#code = datetime.strptime(dateCreate[:10], '%d.%m.%Y')
		#id = ID.format(date = code.strftime("%Y%m%d"), author = author, name = name)

		#if not self.__TryOpen(id):
		self.__data = [name, author, dateCreate, ver, description, shortDescription, None, verDate]
		self.__CreateFullDescription(fullDescription)
			#self.__TryCreate(id)
		#else: 
			#print('try open+')
			#self.__Load(id)
	
	def __str__(self):
		out =  "Program name: \"{}\"\nVersion {} from {}".format(self.name, self.ver, self.verDate)
		out += "\nAuthor: {}".format(self.author)
		out += "\nDate Create: {}".format(self.dateCreate)
		
		if self.__data[5]:
			out += "\nShort description:\n"
		else:
			out += "\nDescription:\n"
		out += self.description
		
		out += "\n"
		return out
	
	def __CreateFullDescription(self, text):
		if not text: return None
		n = len(Information.__inf_params)
		aim = -1
		for i in range(n):
			if Information.__inf_params[i] == 'fullDescription':
				aim = i
				continue
			text = text.replace("{" + Information.__inf_params[i] + "}", str(self.__data[i]))
		self.__data[aim] = text
	
	def __TryOpen(self, id):
		path = FilesPath.format(id = id, extension = ".txt")

		try:
			file = open(path, 'rt', encoding = Encoding)
			valide = False
			for line in file:
				if line == id + '\n': 
					valide = True
					break
			file.close()
			if not valide:
				return False
		except:
			return False
			
		return True
	
	def __TryCreate(self, id):
		path = FilesPath.format(id = id, extension = ".txt")
		
		file = open(path, 'w', encoding = Encoding)
		file.writelines(self.getValuesInOneString('all', separator = '\t') + '\n')
		file.writelines(id + '\n')
		file.close()
		
	def __Load(self, id):
		print('try load')
		path = FilesPath.format(id = id, extension = ".txt")
		
		file = open(path, 'rt', encoding = Encoding)
		for i in range(2):
			file.readline()
		
		str
		
	
	@property
	def name(self): return str(self.__data[0])
	
	@property
	def author(self): return str(self.__data[1])
	
	@property
	def dateCreate(self): return str(self.__data[2])
	
	@property
	def ver(self): return str(self.__data[3])
	
	@property
	def description(self):
		if self.__data[4]: return str(self.__data[4])
		elif self.__data[5]: return str(self.__data[5])
		else: return str(None)
	
	@property
	def shortDescription(self):
		if self.__data[5]: return str(self.__data[5])
		elif self.__data[4]: return str(self.__data[4])
		else: return str(None)
	
	@property
	def fullDescription(self):
		if self.__data[6]: return str(self.__data[6])
		else: return self.description
	
	@property
	def verDate(self): return self.__data[7]
	
	def getValuesInOneString(self, values, separator = ' ', showValNames = True):
		out = ""
		params = values.replace(' ', '').split(',')
		
		if 'all' in params: params = Information.__inf_params
		
		for each in params:
			if each in Information.__inf_params:
				pos = Information.__inf_params.index(each)
				if showValNames: out += str(Information.__inf_params[pos]) + separator
				out += str(self.__data[pos]) + separator
		return out[:len(out) - 1]
	
if __name__ == "__main__":
	about = Information(  name = "Program info"
						, author = "@che_Gogol"
						, dateCreate = "18.03.2022 18:00"
						, description = "Представление информации о проекте (программе) в структурированном и компактном виде"
						, ver = "0.01", verDate = "19.03.2022")
	print(about)

