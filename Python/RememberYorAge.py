import tkinter as tk
from tkinter import messagebox as MessageBox
from tkinter import font as tkFont
from datetime import datetime
import AboutProject as _about

about = _about.Information(name = "Лабораторная работа №1", author = "Гоголев Георгий Михайлович", ver = "1.00"
						, shortDescription = "Программа «Сколько человек прожил»: дней с учетом високосных и невисокосных годов"
						, fullDescription = "{name}\nВариант N 6\nВыполнил студент 2 курса группы БИК2051\n{author}\nЗадание варианта:{shortDescription}"
						)

Font_main = ("Times New Roman", 12)

class MainWindow:
	def __init__(self, master, width, height):
		# Basic
		self.master = master
		self.master.geometry("{}x{}+{}+{}".format(width, height, (master.winfo_screenwidth() - width) // 2, (master.winfo_screenheight() - height) // 2))
		self.master.title(about.name)
		self.frame = tk.Frame(self.master)
		self.frame.pack()
		
		# Menu bar
		menubar = tk.Menu(self.frame)
		master.config(menu = menubar)
		
		filemenu = tk.Menu(menubar, tearoff = 0)
		filemenu.add_command(label = "Выполнить", command = self.Do)
		filemenu.add_command(label = "Очистить", command = self.ClearData)
		filemenu.add_separator()
		filemenu.add_command(label = "Выход", command = self.Exit)

		menubar.add_cascade(label = "Файл", menu = filemenu)
		menubar.add_cascade(label = "О программе", command = self.ShowHelp)
		
		# frames = panels
		fr_input = tk.Frame(self.frame)
		fr_control = tk.LabelFrame(self.frame, borderwidth = 2, relief = tk.RIDGE, text = "Управление программой", font = Font_main)
		
		# objects
		tk.Label(self.frame, width = width, font = Font_main, text = "Задание:\n" + about.shortDescription, justify = tk.LEFT, anchor = 'w').pack(side = tk.TOP, fill = tk.BOTH)
		
		fr_input.pack(side = tk.TOP, fill = tk.X, expand = True)
		tk.Label(fr_input, font = Font_main, text = "Введите дату рождения (можно и время):", justify = tk.LEFT).grid(row = 0, column = 0, sticky = tk.W)
		tk.Label(fr_input, font = Font_main, text = "Введите дату расчета или оставьте пустой:", justify = tk.LEFT).grid(row = 1, column = 0, sticky = tk.W)
		self.tBirthday = tk.Entry(fr_input, font = Font_main, width = 25)
		self.tBirthday.grid(row = 0, column = 1, sticky = tk.W+tk.E, padx = 5)
		self.tBirthday.focus()
		self.tToday = tk.Entry(fr_input, font = Font_main, width = 25)
		self.tToday.grid(row = 1, column = 1, sticky = tk.W+tk.E, padx = 5)
		
		fr_control.pack(side = tk.TOP, fill = tk.X, pady = 5, padx = 3, ipady = 3)
		tk.Button(fr_control, font = Font_main, text = "Очистить", command = self.ClearData).pack(side = tk.RIGHT, padx = 5)
		tk.Button(fr_control, font = Font_main, text = "Выполнить" , command = self.Do).pack(side = tk.RIGHT, padx = 5)
		
		self.lRes = tk.Label(self.frame, font = Font_main, text = "Результат будет выведен здесь.", justify = tk.LEFT, anchor = 'w')
		self.lRes.pack(side = tk.TOP, fill = tk.BOTH)
	def ShowHelp(self): self.ShowMes(text = str(about))
	def ShowMes(self, text = 'debug', type = 'info'):
		type = type.lower()
		tit = about.getValuesInOneString("name, ver")[5:]
		if type == 'error':
			MessageBox.showerror(title = tit, message = text)
		else:
			MessageBox.showinfo(title = tit, message = text)
	def Do(self):
		self.lRes['text'] = 'Результат не определен... Вероятна ошибка вычислений'
		if not self.tBirthday.get(): 
			self.ShowMes('Не введена дата!', 'error')
			return
		mydate, today = GetRevelanceDates(self.tBirthday.get(), self.tToday.get())
		
		if mydate:
			delta = (today - mydate)
			print ('Разница между датами: {}'.format(delta))
			if delta.days > 0:
				self.lRes['text'] = "На {} прожито {} дней".format(today.strftime("%d.%m.%Y"), delta.days)
				if delta.days > 365: self.lRes['text'] += " (что состовляет {} лет)".format(round(delta.days / 365, 2))
			else: self.ShowMes("Введенная дата рождения некорректна! Она больше заданной даты (или сегодня)!", 'error')
		else:
			self.ShowMes("Введенная дата рождения некорректна! Пожалуйста, проверьте введенные данные.", 'error')
		
	def ClearData(self):
		self.tBirthday.delete(0, tk.END)
		self.tToday.delete(0, tk.END)
		self.lRes['text'] = "Результат будет выведен здесь."
	def Exit(self): self.master.destroy()

def main():
	root = tk.Tk()
	MainWindow(root, 620, 190)
	root.mainloop()

def ParseDate(input):
	spase = 0
	points = 0
	colons = 0
	output = '\n'
	
	print("\nParse " + input)
	for each_sym in input:
		sym = ord(each_sym)
		if sym < 48:
			if sym == 46:
				points += 1
			elif each_sym in './-':
				each_sym = '.'
				points += 1
			elif sym == 32:
				spase += 1
			else: return False
			if spase > 1 or points > 2:
				return False
		elif sym == 58:
			colons += 1
			if colons > 1: return False
		elif sym > 58: return False
			
		if output == '\n':
			output = each_sym
		else: output += each_sym
		
	str_length = len(output)
	century = int(output[6:8])
	if century <= int(datetime.now().year) - 2000: century = '20'
	else: century = '19'
	if str_length == 7:
		output = output[:3] + '0' + output[3:5] + century + output[5:] + " 00:00"
	elif str_length == 8:
		output = output[:6] + century + output[6:] + " 00:00"
	elif str_length == 9:
		output = output[:3] + '0' + output[3:] + " 00:00"
	elif str_length == 10:
		output += " 00:00"
	elif str_length == 13:
		if colons == 0: output = output[:6] + century + output[6:]
		else: output = output[:3] + '0' + output[3:5] + century + output[5:]
	elif str_length == 14:
		output = output[:6] + century + output[6:]
	elif str_length == 15:
		output = output[:3] + '0' + output[3:]
	
	print("String: " + output + "\tDatetime: ", end = '')
	
	try:
		output = datetime.strptime(output, '%d.%m.%Y %H:%M')
	except ValueError: output = False
	
	print(output, end = '\n\n')
	return output

def GetRevelanceDates(nes_date, addit_date = None):
	dt_mydate = ParseDate(nes_date)

	if not addit_date: dt_today = datetime.now()
	else: dt_today = ParseDate(addit_date)
	
	return dt_mydate, dt_today

if __name__ == '__main__': main()

