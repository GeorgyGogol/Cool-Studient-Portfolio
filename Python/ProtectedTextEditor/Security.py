import AboutProject as _about

__inf = _about.Information(
			name = 'Security mod'
		,	dateCreate = '24.03.2022'
		,	author = 'GeorgyGogol'
		,	description = 'Модуль для реализации возможности шифрования'
		,	ver = 'a1'
		,	verDate = '24.03.2022 0:10'
		)
__DEBUG = None

from hashlib import sha1

def Shuffle(text, direction = 1):
	out = ""
	if direction == 1:
		L = len(text)
		for i in range(0, L // 2):
			out += text[i]
			out += text[L - i - 1]
		if L % 2 != 0:
			out += text[L // 2]
	else:
		out1, out2 = "", ""
		L = len(text)
		L = L - L % 2
		for i in range(0, L, 2):
			out1 += text[i]
			out2 += text[L - 1 - i]
		if len(text) % 2 != 0:
			out1 += text[L]
		out = out1 + out2
	return out
	
def Code(text, password, direction = 1):
	out = ""
	k = len(password)
	k = k + k % 2
	if direction == 1:
		for each in text:
			x = ord(each)
			y = int(x * k)
			out += chr(y)
	else:
		for each in text:
			x = ord(each)
			y = int(x / k)
			out += chr(y)
	return out

def MergeTexts(text1, text2):
	out = ""
	l1, l2 = len(text1), len(text2)
	i1, i2 = 0, 0
	while i1 < l1 and i2 < l2:
		out += text1[i1] + text2[i2]
		i1, i2 = i1 + 1, i2 + 1
	while i1 < l1 and i2 >= l2:
		out += text1[i1]
		i1 = i1 + 1
	while i2 < l2 and i1 >= l1:
		out += text2[i2]
		i2 = i2 + 1
	return out
	
def UnMergeText(text, length):
	out1, out2 = "", ""
	L, l1, l2 = len(text), len(text) - length, length
	i, i1, i2 = 0, 0, 0
	while i < L and i2 < l2 and i1 < l1:
		out1 += text[i]
		out2 += text[i + 1]
		i, i1, i2 = i + 2, i1 + 1, i2 + 1
	while i < L and i1 < l1 and i2 >= l2:
		out1 += text[i]
		i, i1 = i + 1, i1 + 1
	while i < L and i2 < l2 and i1 >= l1:
		out2 += text[i]
		i, i2 = i + 1, i2 + 1
	return out1, out2

class ProtectedText:
	def __init__(self, text = ""):
		self.__Text = text
		self.__PassWord = None
		self.__Archive = None
		
		self.updateHashStandart()
		
	def __str__(self):
		return self.__Text
		
	def getHashStandart(self):
		return self.__STANDART
		
	def updateHashStandart(self):
		self.__STANDART = self.getHashCurrent()
		
	def getHashCurrent(self):
		return sha1(bytes(self.__Text, encoding = 'UTF-8')).hexdigest()
		
	def isTextChange(self):
		if self.getHashStandart() == self.getHashCurrent():
			return False
		else: return True
		
	def getText(self):
		return self.__Text
	
	def setText(self, txt):
		self.__Text = txt
		
	@property
	def text(self):
		return self.__Text
		
	def protect(self, password, force = False):
		if force: print(ProtectedText.__name__ + ": Force protect")
		if not self.isProtected() and len(password) > 4 or force:
			self.__Text = Shuffle(self.__Text, 1)
			self.__Text = Code(self.__Text, password, 1)
			password = sha1(bytes(password, encoding = 'UTF-8')).hexdigest()
			self.__Text = MergeTexts(self.__Text, password)
			self.__PassWord = len(password)
			print("ProtectedText.protect: Success")
		elif len(password) < 5:
			print("ProtectedText.protect: Password is too short")
		else:
			print("ProtectedText.protect: Cannot protect already protected text")
	
	def unprotect(self, password, force = False):
		if force: print(ProtectedText.__name__ + ": Force unprotect")
		if self.isProtected() or force:
			hash = sha1(bytes(password, encoding = 'UTF-8')).hexdigest()
			__Text, __PassWord = UnMergeText(self.__Text, len(hash))
			
			if hash != __PassWord:
				print("ProtectedText.unprotect: Uncorrect password. Decode denied!")
				raise Exception("UncorrectPassword")
			
			self.__Text = Code(__Text, password, -1)
			self.__Text = Shuffle(self.__Text, -1)
			
			self.__PassWord = False
			print("ProtectedText.unprotect: Success")
		else: 
			print("ProtectedText.unprotect: Cannot decode unprotected text")
		
	def isProtected(self):
		if self.__PassWord: return True
		else: return False
		
	def isArchive(self):
		if self.__Archive: return True
		else: return False
	
	#def compress(self):
	#	if self.isArchive():
	#		print("ProtectedText.compress: Cannot compress already compressed text")
	#		return
		

if __name__ == '__main__' and not __DEBUG:
	print(__inf)
elif __DEBUG:
	text = ProtectedText('Sed venenatis ipsum lorem, sed tristique sem efficitur eu. Donec eget scelerisque lacus, maximus rhoncus massa. Phasellus dictum at lorem vel tempus')
	password = 'password'

	print('Original:  ' + str(text) + ' ' + text.getHashCurrent())

	text.protect(password)
	print('Scripted:  ' + str(text) + ' ' + text.getHashCurrent() + ' ' + str(text.isProtected()))

	text.unprotect(password)
	print('Descripted:' + str(text) + ' ' + text.getHashCurrent() + ' ' + str(text.isProtected()))
	if not text.isTextChange(): print('Ok')

