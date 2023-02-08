import AboutProject as _about
import tkinter as tk
from tkinter import messagebox as MessageBox
import tkinter.filedialog as fileDialog
from hashlib import sha256
from Security import ProtectedText as SimpleText


ABOUT = _about.Information(name = "Лабораторная работа №4", author = "Гоголев Георгий Михайлович", ver = "1.05", verDate = '25.03.2022 09:40'
						, dateCreate = '19.03.2022'
						, shortDescription = "Дан текст. Заменить в каждом предложении все вхождения заданного слова на заданное новое слово."
						, fullDescription = "{name}\nВариант N 6\nВыполнил студент 2 курса группы БИК2051\n{author}\nЗадание варианта:{shortDescription}"
						)

Font_main = ("Times New Roman", 12)
SupportedFileTypes = (  ("Текстовые файлы", '*.txt')
					,	("Все", '*')
					)
					
MenuBarMenus	 = ("File", ("New", "Open", 		"SaveAs", 		   "SaveProtected",			"Close", 0, "Exit"), 	"Text", ("Search", "Replace"),   "Help", None)
MenuBarMenus_rus = ("Файл", ("Новый", "Открыть...", "Сохранить как...", "Сохранить (защищенно)", "Закрыть", 0, "Выход"), "Текст", ("Найти", "Заменить"), "О программе", None)

def ReadText(object):
	tmp = object.get(1.0, tk.END)
	seps = ',.():;?\n'
	
	for each in seps:
		tmp = tmp.replace(each, '')
		
	tmp = tmp.split(' ')
	
	for i in range(len(tmp) - 1):
		wordsStat.add(tmp[i].lower())
	wordsStat.add(tmp[i])
	
	wordsStat.Print()

	return object.get(1.0, tk.END)
		
def main():
	root = tk.Tk()
	MainWindow(root, 720, 275)
	root.mainloop()

class BoxForText:
	__Notsymbols = '-=+'
	def __init__(self):
		self.dict = {}
		self.count = 0
		
	def add(self, word, next_word = None):
		if word in BoxForText.__Notsymbols or word.isdigit(): return
		if word not in self.dict:
			self.dict[word] = 0
			self.count = self.count + 1
		self.dict[word] = self.dict[word] + 1
		
	def Print(self):
		print('Dict count: ' + str(self.count))
		for e in self.dict:
			print(str(e) + ' ' + str(self.dict[e]))

class MainWindow(tk.Frame):
	def __init__(self, master, width, height):
		# Basic
		self.master = master
		self.master.geometry("{}x{}+{}+{}".format(width, height, (master.winfo_screenwidth() - width) // 2, (master.winfo_screenheight() - height) // 2))
		self.frame = tk.Frame(self.master)
		self.frame.pack()
		spanX = 5
		
		# Menu bar
		self.menubar = tk.Menu(self.frame)
		master.config(menu = self.menubar)
		
		for i in range(0, len(MenuBarMenus), 2):
			filemenu = tk.Menu(self.menubar, tearoff = 0)
			try:
				for i2 in range(len(MenuBarMenus[i + 1])):
					if type(MenuBarMenus[i + 1][i2]) == str:
						filemenu.add_command(label = MenuBarMenus_rus[i + 1][i2], 
									command = lambda menu = MenuBarMenus[i], com = MenuBarMenus[i + 1][i2]: self.__menubarClicked(menu, com))
					else:
						if MenuBarMenus[i + 1][i2] == 0: filemenu.add_separator()
				self.menubar.add_cascade(label = MenuBarMenus_rus[i], menu = filemenu)
			except:
				self.menubar.add_cascade(label = MenuBarMenus_rus[i], command = lambda menu = MenuBarMenus[i] : self.__menubarClicked(menu))
		
		# objects
		tk.Label(self.frame, font = Font_main, justify = tk.LEFT, anchor = 'w', text = "Задание:\n" + ABOUT.shortDescription, width = width).pack(side = tk.TOP, fill = tk.X, padx = spanX)
		self.tText = tk.Text(self.frame, font = Font_main, wrap = tk.WORD, width = width - 10, height = height, state = tk.DISABLED)
		scroll = tk.Scrollbar(self.frame)
		self.tText.config(yscrollcommand = scroll.set)
		
		scroll.pack(side = tk.RIGHT, fill = tk.Y)
		self.tText.pack(side = tk.LEFT, fill = tk.BOTH, padx = spanX, pady = 5)
		
		# values
		self.__filename = str(None)
		
		self.New()
		
	def __menubarClicked(self, menu, comm = None):
		menu, comm = str(menu), str(comm)
		print ("Menu \"{}\" Command: \"{}\"".format(menu, comm))
		
		try:
			if menu == "File":
				if comm == "New": self.New()
				elif comm == "Open": self.Open()
				elif comm == "SaveAs": self.SaveAs()
				elif comm == "SaveProtected": self.SaveProtected()
				elif comm == "Exit": self.Exit()
				elif comm == "Close": self.Close()
				else: raise Exception("ChooseException")
			elif menu == "Text":
				if comm == "Search": self.Search()
				elif comm == "Replace": self.Replace()
				else: raise Exception("ChooseException")
			elif menu == "Help" and comm == "None": self.ShowHelp()
			else: raise Exception("ChooseException")
		except Exception as e:
			if str(e) == "ChooseException":
				print("Warning: Action \"{}\" in menu \"{}\" is not created / added".format(comm, menu))
			else: print(e)
	
	def New(self, file_name = "Безымянный"): 
		self.tText.delete(1.0, tk.END)
		self.tText.config(state = tk.NORMAL)
		self.master.title(ABOUT.name + ": " + file_name)
		self.menubar.entryconfig("Текст", state = "normal")
	
	def Open(self, filename = None):
		if not filename:
			print("Open ", end = '')
			__filename = fileDialog.askopenfilename(title = "Открыть файл...", filetypes = SupportedFileTypes)
		else:
			self.__filename = filename
			return
		if __filename:
			print(__filename)
			try:
				file = open(__filename, 'rt', encoding = 'UTF-8')
			except Exception as e:
				self.ShowMes("Ошибка открытия файла", 'error')
				print(e)
			else:
				try:
					txt = file.read()
					if txt[0] == chr(20):
						print("Read protected file")
						self.ShowPassWindow()
						if self.__filename != str(None):
							text = self.ReadText(txt)
							self.New(file_name = __filename)
							self.tText.insert(tk.END, text)
						else: print("Input password canceled, open canceled")
					else:
						self.New(file_name = __filename)
						self.tText.insert(tk.END, txt)
				except Exception as e:
					if str(e) == "CheckException":
						self.ShowMes("Пароль неверен!", 'error')
					elif e == UnicodeDecodeError:
						self.ShowMes("Ошибка чтения файла", 'error')
					else:
						self.ShowMes("Ошибка программы при чтении файла", 'error')
					self.Close()
					print(e)
				file.close()
		else: print("Open canceled")
	
	def SaveAs(self):
		print("Save as ", end = '')
		__filename = fileDialog.asksaveasfilename(title = "Сохранить файл...", filetypes = SupportedFileTypes, defaultextension = ".txt")
		if __filename:
			print(__filename)
			try:
				file = open(__filename, 'wt', encoding = 'UTF-8')
			except Exception as e:
				self.ShowMes("Ошибка открытия файла", 'error')
				print(e)
			else:
				self.master.title(ABOUT.name + ": " + __filename)
				file.write(ReadText(self.tText))
				file.close()
				print("SaveAs: succsessful")
		else: print("SaveAs canceled")
		
	def Close(self):
		self.tText.delete(1.0, tk.END)
		self.tText.config(state = tk.DISABLED)
		self.master.title(ABOUT.name + ": ожидание команды")
		self.menubar.entryconfig("Текст", state = tk.DISABLED)
	
	def Search(self):
		searchWindow = tk.Toplevel(self.master)
		wind = SearchWindow(searchWindow, self)
		
	def Replace(self):
		replaceWindow = tk.Toplevel(self.master)
		wind = ReplaceWindow(replaceWindow, self)
		
	def ShowHelp(self): self.ShowMes(text = str(ABOUT))
	
	def ShowMes(self, text = 'debug', type = 'info'):
		type = type.lower()
		tit = ABOUT.getValuesInOneString("name, ver")[5:]
		if type == 'error':
			MessageBox.showerror(title = tit, message = text)
		else:
			MessageBox.showinfo(title = tit, message = text)
	
	def Exit(self): self.master.destroy()
	
	def SearchStringInText(self, what):
		count = self.tText.get(1.0, tk.END).count(what)
		return count
		
	def tText_get(self, start = None, end = None):
		check = sha256(bytes(self.__filename, encoding = 'UTF-8')).hexdigest()
		if start != 1.0 and end != check:
			print("Error: Checkpoint not passed")
			raise Exception("CheckException")

		out = SimpleText(self.tText.get(1.0, tk.END))
		out.protect(check)
		
		return out.getText()
		
	def ReadText(self, text):
		check = sha256(bytes(self.__filename, encoding = 'UTF-8')).hexdigest()
		
		text = SimpleText(text[1:])
		try:
			text.unprotect(check, force = 1)
		except Exception as e:
			raise Exception("CheckException")			
			
		return text.getText()[:-1]
		
	def SaveProtected(self):
		print("Save as (protect)", end = ' ')
		__filename = fileDialog.asksaveasfilename(title = "Сохранить файл...", filetypes = SupportedFileTypes, defaultextension = ".txt")
		if __filename:
			print(__filename)
			
			self.ShowPassWindow()
			if self.__filename != str(None):
				simSaladdin = sha256(bytes(self.__filename, encoding = 'UTF-8')).hexdigest()
				END = sha256(bytes(self.__filename, encoding = 'UTF-8')).hexdigest()
			else: return
			
			try:
				file = open(__filename, 'wt', encoding = 'UTF-8')
				text = self.tText_get(1.0, END)
			except Exception as e:
				if str(e) == "CheckException":
					self.ShowMes("При защите файла возникла ошибка невалидного пароля!", 'error')
				else:
					self.ShowMes("Ошибка открытия файла для сохранения", 'error')
				print(e)
			else:
				self.master.title(ABOUT.name + ": " + __filename)
				file.write(chr(20))
				file.write(text)
				file.close()
				print("SaveProtected: succsessful")
		else: print("SaveProtected canceled")

	def ShowPassWindow(self):
		passwordWindow = tk.Toplevel(self.master)
		InputPassword(passwordWindow, self)
		self.master.wait_window(passwordWindow)

class SearchWindow(tk.Frame):
	def __init__(self, master, parent):
		# Basic
		self.master = master
		width, height = 400, 110
		self.master.geometry("{}x{}+{}+{}".format(width, height, (master.winfo_screenwidth() - width) // 2 + width, (master.winfo_screenheight() - height) // 2 - height * 3 // 2))
		self.master.title("Поиск")
		self.master.resizable(0, 0)
		self.frame = tk.Frame(self.master)
		self.frame.pack()
		self.parent = parent
		
		# Frames
		fr_results = tk.Frame(self.frame)
		fr_buttons = tk.Frame(self.frame)
		
		# Objects
		spanX = 5
		tk.Label(self.frame, font = Font_main, justify = tk.LEFT, anchor = 'w', text = "Введите искомую фразу", width = width).pack(side = tk.TOP, fill = tk.X, padx = spanX)
		self.eSearch = tk.Entry(self.frame, font = Font_main)
		self.eSearch.pack(side = tk.TOP, fill = tk.X, padx = spanX * 2)
		
		fr_results.pack(side = tk.TOP, fill = tk.X, padx = spanX)
		tk.Label(fr_results, font = Font_main, justify = tk.LEFT, anchor = 'w', text = "Найдено:").grid(row = 0, column = 0, padx = spanX)
		self.lSearchedCount = tk.Label(fr_results, font = Font_main, justify = tk.LEFT, anchor = 'w', text = "0 вхождений")
		self.lSearchedCount.grid(row = 0, column = 1, padx = spanX)
		
		fr_buttons.pack(side = tk.TOP, fill = tk.X, padx = spanX)
		tk.Button(fr_buttons, font = Font_main, text = "Закрыть", command = self.Close).pack(side = tk.RIGHT, padx = 5)
		tk.Button(fr_buttons, font = Font_main, text = "Очистить", command = self.ClearSearch).pack(side = tk.RIGHT, padx = 5)
		tk.Button(fr_buttons, font = Font_main, text = "Найти", command = self.Search).pack(side = tk.RIGHT, padx = 5)
	
	def Close(self): self.master.destroy()
	
	def ClearSearch(self):
		self.eSearch.delete(0, tk.END)
		self.lSearchedCount['text'] = "0 вхождений"
		
	def Search(self):
		self.lSearchedCount['text'] = str(self.parent.SearchStringInText(self.eSearch.get())) + " вхождений"

class ReplaceWindow(tk.Frame):
	def __init__(self, master, parent):
		# Basic
		self.master = master
		width, height, spanX = 400, 140, 5
		self.master.geometry("{}x{}+{}+{}".format(width, height, (master.winfo_screenwidth() - width) // 2 + width, (master.winfo_screenheight() - height) // 2 - height * 3 // 2))
		self.master.title("Замена")
		self.master.resizable(0, 0)
		self.frame = tk.Frame(self.master)
		self.frame.pack()
		self.parent = parent
		
		# Frames
		fr_buttons = tk.Frame(self.frame)
		
		# Objects
		tk.Label(self.frame, font = Font_main, justify = tk.LEFT, anchor = 'w', text = "Введите, что нужно заменить", width = width).pack(side = tk.TOP, fill = tk.X, padx = spanX)
		self.eSearch = tk.Entry(self.frame, font = Font_main)
		self.eSearch.pack(side = tk.TOP, fill = tk.X, padx = spanX * 2)
		
		tk.Label(self.frame, font = Font_main, justify = tk.LEFT, anchor = 'w', text = "Введите, чем (на что) нужно заменить", width = width).pack(side = tk.TOP, fill = tk.X, padx = spanX)
		self.eReplace = tk.Entry(self.frame, font = Font_main)
		self.eReplace.pack(side = tk.TOP, fill = tk.X, padx = spanX * 2)
		
		fr_buttons.pack(side = tk.TOP, fill = tk.X, padx = spanX, pady = spanX)
		tk.Button(fr_buttons, font = Font_main, text = "Закрыть", command = self.Close).pack(side = tk.RIGHT, padx = 5)
		tk.Button(fr_buttons, font = Font_main, text = "Очистить", command = self.Clear).pack(side = tk.RIGHT, padx = 5)
		tk.Button(fr_buttons, font = Font_main, text = "Выполнить замену", command = self.DoReplace).pack(side = tk.RIGHT, padx = 5)
	
	def Close(self): self.master.destroy()
	
	def Clear(self):
		self.eSearch.delete(0, tk.END)
		self.eReplace.delete(0, tk.END)
	
	def DoReplace(self):
		txt = str(self.parent.tText.get(1.0, tk.END))
		aim = str(self.eSearch.get())
		rep = str(self.eReplace.get())
		
		self.parent.tText.delete(1.0, tk.END)
		self.parent.tText.insert(1.0, txt.replace(aim, rep))
		
class InputPassword(tk.Frame):
	def __init__(self, master, parent):
		# Basic
		self.master = master
		self.parent = parent
		width, height, spanX = 330, 94, 5
		self.master.geometry("{}x{}+{}+{}".format(width, height, (master.winfo_screenwidth() - width) // 2 + width, (master.winfo_screenheight() - height) // 2 - height * 3 // 2))
		self.master.title("Защита файла")
		self.master.grab_set()
		self.master.focus_set()
		
		# Frames
		self.frame = tk.Frame(self.master)
		self.frame.pack()
		fr_buttons = tk.Frame(self.frame)
		
		# Objects
		tk.Label(self.frame, font = Font_main, justify = tk.LEFT, anchor = 'w', text = "Для продолжения необходимо ввести пароль:", width = width).pack(side = tk.TOP, fill = tk.X, padx = spanX)
		self.ePass = tk.Entry(self.frame, font = Font_main)
		self.ePass.pack(side = tk.TOP, fill = tk.X, padx = spanX)
		
		fr_buttons.pack(side = tk.TOP, fill = tk.X, padx = spanX, pady = spanX)
		tk.Button(fr_buttons, font = Font_main, text = "Отмена", command = self.Cancel).pack(side = tk.RIGHT, padx = 5)
		tk.Button(fr_buttons, font = Font_main, text = "Ввод", command = self.Enter).pack(side = tk.RIGHT, padx = 5)
	
	def __str__(self):
		return 'InputPassword'
	
	def Close(self): self.master.destroy()
	
	def Cancel(self):
		print(str(self) + " Cancel")
		self.parent.Open(str(None))
		self.Close()
	
	def Enter(self):
		print(str(self) + " Enter")
		self.parent.Open(self.ePass.get())
		self.Close()
		
wordsStat = BoxForText()

if __name__ == '__main__': main()

