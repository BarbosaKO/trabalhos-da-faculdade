import gi
gi.require_version("Gtk", "3.0")
from gi.repository import Gtk

# TKinter lousa ********************************************
from tkinter import *
from tkinter.colorchooser import askcolor

class Paint(object):

    DEFAULT_PEN_SIZE = 5.0
    DEFAULT_COLOR = 'black'

    def __init__(self):
        self.root = Tk()

        self.pen_button = Button(self.root, text='pen', command=self.use_pen)
        self.pen_button.grid(row=0, column=0)

        self.brush_button = Button(self.root, text='brush', command=self.use_brush)
        self.brush_button.grid(row=0, column=1)

        self.color_button = Button(self.root, text='color', command=self.choose_color)
        self.color_button.grid(row=0, column=2)

        self.eraser_button = Button(self.root, text='eraser', command=self.use_eraser)
        self.eraser_button.grid(row=0, column=3)

        self.choose_size_button = Scale(self.root, from_=1, to=10, orient=HORIZONTAL)
        self.choose_size_button.grid(row=0, column=4)

        self.c = Canvas(self.root, bg='white', width=600, height=600)
        self.c.grid(row=1, columnspan=5)

        self.setup()
        self.root.mainloop()

    def setup(self):
        self.old_x = None
        self.old_y = None
        self.line_width = self.choose_size_button.get()
        self.color = self.DEFAULT_COLOR
        self.eraser_on = False
        self.active_button = self.pen_button
        self.c.bind('<B1-Motion>', self.paint)
        self.c.bind('<ButtonRelease-1>', self.reset)

    def use_pen(self):
        self.activate_button(self.pen_button)

    def use_brush(self):
        self.activate_button(self.brush_button)

    def choose_color(self):
        self.eraser_on = False
        self.color = askcolor(color=self.color)[1]

    def use_eraser(self):
        self.activate_button(self.eraser_button, eraser_mode=True)

    def activate_button(self, some_button, eraser_mode=False):
        self.active_button.config(relief=RAISED)
        some_button.config(relief=SUNKEN)
        self.active_button = some_button
        self.eraser_on = eraser_mode

    def paint(self, event):
        self.line_width = self.choose_size_button.get()
        paint_color = 'white' if self.eraser_on else self.color
        if self.old_x and self.old_y:
            self.c.create_line(self.old_x, self.old_y, event.x, event.y,
                               width=self.line_width, fill=paint_color,
                               capstyle=ROUND, smooth=TRUE, splinesteps=36)
        self.old_x = event.x
        self.old_y = event.y

    def reset(self, event):
        self.old_x, self.old_y = None, None
#************************************************************
builder = Gtk.Builder()
builder.add_from_file("main_interface.glade")

class Handler(object):
	def __init__(self, **kwargs):
		super(Handler,self).__init__(**kwargs)
		self.meu_menu = builder.get_object("meu_menu")
		self.btn_lousa = builder.get_object("btn_lousa")
		self.mostrar_texto = builder.get_object("mostrar_texto")
		self.caixa_texto = builder.get_object("caixa_texto")



	def on_minha_janela_destroy(self, window):
		Gtk.main_quit()

	def on_btn_lousa_activate(self, menuitem):
		Paint()

	def on_salvar_texto_activate(self, menuitem):

		self.janela_salvar = builder.get_object("janela_salvar")
		self.btn_salvar = builder.get_object("btn_salvar")
		self.btn_fechar = builder.get_object("btn_fechar")
		self.lb_dig_nome = builder.get_object("lb_dig_nome")
		self.texto_nome_arq = builder.get_object("texto_nome_arq")
		self.janela_salvar.run()

	def on_btn_salvar_clicked(self, button):
		ini_texto = self.caixa_texto.get_start_iter()
		fim_texto = self.caixa_texto.get_end_iter()
		txt = self.caixa_texto.get_text(ini_texto, fim_texto, True)

		nome_arq = self.texto_nome_arq.get_text()

		with open(nome_arq, 'w') as f:
			f.write(txt)

		self.janela_salvar.hide()

	def on_btn_fechar_clicked(self,button):
		self.janela_salvar.hide()

	def on_janela_salvar_close(self, widget):
		self.janela_salvar.hide()

builder.connect_signals(Handler())
janela = builder.get_object("minha_janela")
janela.show_all()
Gtk.main()