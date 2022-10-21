import pygame
import tkinter as tkr
from tkinter.filedialog import askdirectory
import os

music_player = tkr.Tk()
music_player.title("Music Player")
music_player.geometry('500x400')

directory = askdirectory()
os.chdir(directory)

song_list = os.listdir()

playlist = tkr.Listbox(music_player, font = "verdana 12 bold",fg='navy', bg = 'gold', selectmode = tkr.SINGLE)

x = 0
for i in song_list:
    playlist.insert(x,i)
    x += 1

pygame.init()
pygame.mixer.init()

def play():
    pygame.mixer.music.load(playlist.get(tkr.ACTIVE))
    var.set(playlist.get(tkr.ACTIVE))
    pygame.mixer.music.play()

def pause():
    pygame.mixer.music.pause()

def stop():
    pygame.mixer.music.stop()

def unpause():
    pygame.mixer.music.unpause()

Button1 = tkr.Button(music_player, width = 5, height = 3, font = 'verdana 12 bold', text = 'PLAY', command = play, bg = 'navy', fg = 'gold')

Button2 = tkr.Button(music_player, width = 5, height = 3, font = 'verdana 12 bold', text = 'STOP', command = stop, bg = 'navy', fg = 'gold')

Button3 = tkr.Button(music_player, width = 5, height = 3, font = 'verdana 12 bold', text = 'PAUSE', command = pause, bg = 'navy', fg = 'gold')

Button4 = tkr.Button(music_player, width = 5, height = 3, font = 'verdana 12 bold', text = 'UNPAUSE', command = unpause, bg = 'navy', fg = 'gold')

var = tkr.StringVar()
song_title = tkr.Label(music_player,font = 'verdana 12 bold', textvariable = var)

song_title.pack()
Button1.pack(fill = 'x')
Button2.pack(fill = 'x')
Button3.pack(fill = 'x')
Button4.pack(fill = 'x')

playlist.pack(fill = 'both', expand = 'yes')

music_player.mainloop()
