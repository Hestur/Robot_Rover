# The User Interface Class definitions

from os import system

import msvcrt

class User_Interface:
  def __init__(self, RC, IF_Type):
    self.__RC = RC #RoboCar Object Reference
    self.__IF_Type = IF_Type

  def Clear_Screen(self):
    print('Clear User_Interface Screen')
    

  def Print_Menu(self):
    print('User_Interface Menu')

  def Read_Key(self):
        print('Read a key')

class Terminal_Interface(User_Interface):
  def __init__(self,RC):
    User_Interface.__init__(self,RC,'Terminal')
    self.__RC = RC  # RoboCar Object Reference

    self.Print_Menu()
    
   
  def Clear_Screen(self):
    system('cls')

  def Print_Menu(self):
    self.Clear_Screen()
    print('---------------------', self.__RC.Get_Name(),'---------------------')
    print('                                                                   ')
    print('           1: Handle Missions                                 ')
    print('           2: Handle Sensors                                  ')
    print('           3: Handle Rover                                    ')
    print('           4: Data Visualization                              ')
    print('           q: Quit Rover Mission Control                      ')
    print('                                                              ')
    print('----------------------', self.__RC.Get_Interface_Type(), '------------------------')

  def Read_Key(self):
    if msvcrt.kbhit():
      bytekey = msvcrt.getch()
      if bytekey == b'\xe0':
        bytekey = msvcrt.getch() #Special key - read again

        key = bytekey.decode('ASCII')

        if key == 'H':
          return 'Arrow_Up'
        elif key == 'P':
          return 'Arrow_Down'
        elif key == 'M':
          return 'Arrow_Right'
        elif key == 'K':
          return 'Arrow_Left'
      else:
        return bytekey.decode('ASCII') #Anything else   




