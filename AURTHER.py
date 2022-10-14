from importlib.resources import path
import pyttsx3
import speech_recognition as sr  
import datetime 
import time
import wikipedia  
import webbrowser
import os
import smtplib
import sys
import random
import re
from bs4 import BeautifulSoup
import requests
import pyautogui
import pywhatkit
import pyjokes
import cv2
import PyPDF2


engine = pyttsx3.init('sapi5')
voices = engine.getProperty('voices')
# print(voices[0].id)
engine.setProperty('voice', voices[0].id)
engine.setProperty('rate', 175)


def speak(audio):
    engine.say(audio)
    engine.runAndWait()


def takeCommand():

    r = sr.Recognizer()
    with sr.Microphone() as source:
        print("Listening...")
        audio = r.listen(source)

    try:
        print("Recognizing...")
        query = r.recognize_google(audio, language='en-in')
        print(f"User said: {query}\n")

    except Exception as e:
        # print(e)
        print("Say that again please...")
        #speak("Say that again please")
        return "None"
    return query


def wishMe():
    speak("Initializing Arthur")
    speak("Starting all systems applications")
    speak("Installing and checking all drivers")
    speak("Caliberating and examining all the core processors")
    speak("Checking the internet connection")
    speak("Wait a moment sir")
    speak("All drivers are up and running")
    speak("All systems have been activated")
    speak("Now I am online")
    tt = datetime.datetime.now().strftime("%I:%M %p")
    hour = int(datetime.datetime.now().hour)
    if hour >= 5 and hour < 12:
        print(f"Good Morning!. its {tt}, I am Arthur. Online and ready sir. Please tell me how may I help you ?")
        speak(f"Good Morning!. its {tt}, I am Arther. Online and ready sir. Please tell me how may I help you ?")

    elif hour >= 12 and hour < 17:
        print(f"Good Afternoon!.its {tt} , I am Arthur, Online and ready sir. Please tell me how may I help you ?")
        speak(f"Good Afternoon!.its {tt} , I am Arthur, Online and ready sir. Please tell me how may I help you ?")

    elif hour >= 18 and hour < 20:
        print(f"Good Evening!. its {tt} ,I am Aurther. Online and ready sir. Please tell me how may I help you ?")
        speak(f"Good Evening!. its {tt} ,I am Aurther. Online and ready sir. Please tell me how may I help you ?")

    else:
        print(f"its {tt}.  sir!, you are wake till now! , Please tell me how can I help you ?")
        speak(f"its {tt}.  sir!, you are wake till now! , Please tell me how can I help you ?")
    

def daynight():
    hour = int(datetime.datetime.now().hour)
    if hour >= 5 and hour < 17:
        speak("its day time sir")

    elif hour >= 17 and hour <= 20:
        speak("its evening sir ")

    else: 
        speak("its night sir")


def goodnight():
    hour = int(datetime.datetime.now().hour)
    if  hour>=5 and hour <=21:
        speak("Alright sir, going offline. It was nice working with you, thanks for using me sir, have a good day")
        sys.exit()

    else:
        speak("Alright sir, going offline. It was nice working with you, thanks for using me sir, goodnight sir")
        sys.exit()


def pdf_reader():
        book =open('sem.pdf.pdf','rb')
        pdfReader = PyPDF2.PdfFileReader(book)  # pip install PyPDF2
        pages =pdfReader.numPages
        speak(f"Total numbers of pages in this book {pages} ")
        speak("sir please enter the page number i have to read")
        pg=int(input("Please enter the page number: "))
        page =pdfReader.getPage(pg)
        text =page. extractText()
        speak(text)


def news():
    main_url = "http://newsapi.org/v2/top-headlines?sources=techcrunch&apikey-83263a48521a48a797182dbc3926e513"

    main_page = requests.get(main_url).json()

    articles = main_page["articles"]

    head = []
    day = ["first", "second ", "third", "fourth", "fifth",
           "sixth ", "seventh", "eighth", "ninth", "tenth"]
    for ar in articles:
        head.append(ar["title"])
    for i in range(len(day)):

        speak(F"today's {day[i]} news is: {head [i]}")


def alarm(Timing):
    altime = str(datetime.datetime.now().strptime(Timing, "%I:%M %p"))
    # print(altime)
    altime = altime[11:-3]
    # print(altime)
    Hrtime = altime[:2]
    Hrtime = int(Hrtime)
    Mntime = altime[3:5]
    Mntime = int(Mntime)
    print(f"Done, alarm is set for {Timing}")

    while True:
        if Hrtime == datetime.datetime.now().hour:
            if Mntime == datetime.datetime.now().minute:
                print("alarm is running...")
                music_dir = "E:\\songs"
                songs = os.listdir(music_dir)
                #rd = random.choice (songs)
                os.startfile(os.path.join(music_dir, songs[0]))

            elif Mntime < datetime.datetime.now().minute:
                break


def sendEmail(to, content):
    server = smtplib.SMTP('smtp.gmail.com', 587)
    server.ehlo()
    server.starttls()
    server.login(' ', '')
    server.sendmail('', to, content)
    server.close()


if __name__ == "__main__":

    wishMe()
    while True:
        query = takeCommand().lower()

        if 'yourself' in query:
            speak('I am Arthar a virtual python ai developed by avrojit. I am his system assistant')


        elif 'wikipedia' in query:
            speak('Searching wikipedia...')
            query = query.replace(" in wikipedia", "")
            results = wikipedia.summary(query, sentences=3)
            speak("According to Wikipedia")
            print(results)
            speak(results)


        elif 'search' in query or "tell me about" in query:
            query = query.replace("search", "")
            speak("searching"+query)
            pywhatkit.search(query)


        elif 'go to' in query:
            path = "C:/Program Files/Google/Chrome/Application/chrome.exe %s"
            query = query.replace("go to", "")
            pywhatkit.search(query+".com")
            speak("opening" + query)


        elif 'who is' in query:
            path = "C:/Program Files/Google/Chrome/Application/chrome.exe %s"
            query = query.replace("who is", "")
            pywhatkit.search(query)
            speak("showing about " + query)


        elif 'are you single' in query:
            speak('I am in a relationship with wifi')


        elif 'joke' in query:
            speak(pyjokes.get_joke())
            print(pyjokes.get_joke())


        elif 'youtube' in query:
            path = "C:/Program Files/Google/Chrome/Application/chrome.exe %s"
            webbrowser.get(path).open("youtube.com")
            speak("opening" + query)


        elif 'open google' in query:
            speak("Sir, what should i search")
            cm = takeCommand().lower()
            pywhatkit.search(cm)
            speak("searching" + cm)


        elif 'stack overflow' in query:
            path = "C:/Program Files/Google/Chrome/Application/chrome.exe %s"
            webbrowser.get(path).open("stackoverflow.com")
            speak("opening stackoverflow")


        elif 'linkedin' in query:
            path = "C:/Program Files/Google/Chrome/Application/chrome.exe %s"
            webbrowser.get(path).open("linkedin.com")
            speak("opening linkedin")


        elif 'netflix' in query:
            path = "C:/Program Files/Google/Chrome/Application/chrome.exe %s"
            webbrowser.get(path).open("netflix.com")
            speak("opening netflix")


        elif "open pdf reader" in query:
            speak("opening pdf reader")
            apath = "C:/Program Files/Adobe/Acrobat DC/Acrobat/Acrobat.exe"
            os.startfile(apath)


        elif "open command prompt" in query:
            speak("opening command promPt")
            os.system("start cmd")


        elif 'open camera' in query:
            speak("opening camera")
            cap = cv2.VideoCapture(0)
            while True:
                ret, img = cap.read()
                cv2.imshow('webcam', img)
                k = cv2.waitKey(50)
                if k == 27:
                    break
                cap.release()
                #cv2.destroyAllWindows()


        elif 'play' in query:
            song = query.replace('play', '')
            speak('playing ' + song + 'from youtube')
            pywhatkit.playonyt(song)


        elif "music offline" in query:
            speak("playing music ofline")
            music_dir = "E:\\songs"
            songs = os.listdir(music_dir)
            #rd = random.choice (songs)
            os.startfile(os.path.join(music_dir, songs[0]))


        elif 'the time' in query:
            strTime = datetime.datetime.now().strftime("%Y/%m/%d %I:%M %p")
            speak(f"Sir, the time is {strTime}")


        elif 'open code' in query:
            speak("opening vs code")
            codePath = "C:\\Users\AVRAJIT SINGH\AppData\Local\Programs\Microsoft VS Code\Code.exe"
            os.startfile(codePath)


        elif 'day or night' in query:
            daynight()


        elif 'open notepad' in query:
            speak("opening notpad")
            npath = "C:/Program Files/WindowsApps/Microsoft.WindowsNotepad_11.2205.11.0_x64__8wekyb3d8bbwe/Notepad/Notepad.exe"
            os.startfile(npath)


        elif 'send message' in query:
            speak("sending message,please wait amoument")
            pywhatkit.sendwhatmsg("+918250430889", "this is testig protocol", 23, 37)


        elif 'email to Avrajit' in query:

            speak(" sir what should 1 say")
            query = takecommand().lower()
            if "send a file" in query:
                email = 'your@gmail.com'
                password = "your_pašs"
                send_to_email = 'person@gmail.com'
                speak("okay sir, what 1s the subject for this email")
                query = takeCommand().lower()
                subject = query
                speak("and sir, what is the message for this email")
                query2 = takeCommand().lower()
                message = query2
                speak("sir please enter the correct path of the file into the shell")
                file_location = input("please enter the path here")

                speak("please wait, i am sending email now")

                msg = MIMEMultipart()
                msg['From'] = email
                msg['To'] = send_to_email
                msg['Subject'] = subject
                msg.attach(MIMEText(message, "plain"))
            # Setup the attachment
                filename = os.path.basename(file_location)
                attachment = open(file_location, "rb")
                part = MIMEBase('application ', 'octet-stream')
                part.set_payload(attachment.read())
                encoders.encode_base64(part)
                part.add_header('Content -Disposition',
                                "attachment; filename= s" % filename)
            # Attach the attachment to the HIMEMultipart objęct
                msg.attach(part)

                server = smtplib.SMTP('smtp. gmail.com', 587)
                server.starttls()
                server.login(email, password)
                text = msg.as_string()
                server.sendmail(email, send_to_email, text)
                server.quit()
                speak("email has been sent to Avrajit")


        elif "internet speed" in query:

                speak(f"Analysing internet speed,please wait a moment")
                import speedtest
                st = speedtest.Speedtest()
                dl =  int (st.download()/1048576)
                up =  int (st.upload()/1048576)
                
                print(f"sir we have {dl} mb per second downloading speed and {up} mb per second uploading speed")
                speak(f"sir we have {dl} mb per second downloading speed and {up} mb per second uploading speed")


        elif "shut down the system" in query:
            speak("shutting down the system ,please save all your unsaved works")
            os.system("shutdown /s-/t 5")


        elif "restart the system" in query:
            speak("restarting the system")
            os.system("shutdown /r /t 5")


        elif "sleep the system" in query:
            speak("system will go to sleep now")
            os.system("rundll32 . exe powrprof.dll, SetSuspendState 0,1,0")


        elif "temperature" in query:
            search = "temperature in Asansol"
            url = f"https://www.google.com/search?q={search}"
            r = requests.get(url)
            data = BeautifulSoup(r.text, "html.parser")
            temp = data. find("div", class_="BNeawe").text
            speak(f"current {search} is {temp}")
            print(f"current {search} is {temp}")


        elif "how much battery left" in query or "how much power we have" in query or "battery" in query or "power" in query:
            import psutil
            battery = psutil.sensors_battery()
            percentage = battery.percent
            speak(f"sir our system have {percentage} percent battery" )
            if percentage>=75:
                   speak("we have enough power to continue our work")
            elif percentage>=46 and percentage<=75:
                    speak("we should connect our system to charging point to charge our battery")
            elif percentage>=15 and percentage<=30:
                    speak("we don't have enough power to work, please connect to charging")
            elif percentage<=15:
                    speak("we have very low power, please connect to charging the system will shutdown very soon ")


        elif "pdf" in query:
            pdf_reader()


        elif "hide all files" in query or "show this folder" in query or "hide this folder" in query or "show this files" in query:
            
            speak("sir please tell me you want to hide this folder or make it visible for everyone")
            condition = takeCommand().lower()
            if "hide" in condition:
                os.system ("attrib +h /s /d") 
                speak("sir, all the files in this folder are now hidden. ")
            elif "visible" in condition :
                os.system("attrib -h /s /d")
                speak("sir, all the files in this folder are now visible to everyone. be carefull now")
            elif "leave it" in condition or "leave for now" in condition :
                speak("Ok sir")


        elif "quit" in query or "goodbye" in query or "offline" in query  or "bye" in query or "shutdown" in query or "you can sleep" in query:
                goodnight()


        elif "set alarm" in query:
                print("tell me when should i set the alam : ")
                speak("tell me when should i set the alam")
                aa=takeCommand().upper()
                aa= aa.replace(".",":")
                speak("the alarm has set at: "+aa)
                print("the alarm has set at: "+aa)
                (datetime.datetime.now().strftime("%I:%M %p"))
                #print(aa)
                if ((datetime.datetime.now().strftime("%I:%M %p"))==aa) :
                    music_dir = "E:\\songs"
                    songs = os.listdir(music_dir)
                    #rd = random.choice (songs)
                    os.startfile(os.path.join(music_dir, songs[0]))
                    
                    
        elif "set the alarm" in query:
            tt=str(input("tell me when should i set the alarm :"))
            alarm(tt)
            
            
        elif "alarm" in query:
            speak("sir please tell me the time to set alarm. for example, set alarm to 5:30 am")
            tt = takeCommand() 
            tt = tt.replace ("set alarm to ", "") #5:30 a.m.
            tt = tt.replace (".", "") #5:30 am
            tt = tt.upper() #5: 30 AM
            import MyAlarm
            MyAlarm.alarm(tt)
            #set alarm to 5:30 a.m.

        elif 'switch the window' in query:
            pyautogui.keyDown("alt")
            pyautogui.press("tab")
            time.sleep(1)
            pyautogui.keyUp("alt")
        
        
        elif 'thank you' in query or 'thanks' in query:
            print('Welcome Sir,I am pleased to help you')
            speak('Welcome Sir,I am pleased to help you')
            
       
        
        elif "volume up" in query:
            pyautogui.press("volumeup")
        elif "volume down" in query:
            pyautogui.press ("volumedown")
        elif "volume mute" in query or "mute" in query:
            pyautogui.press ("volumemute")
            
            
        elif ' terminate chrome' in query:
            for process in (process for process in psutil.process_iter() if process.name() == "chrome.exe"):
                process.kill()
                speak('Terminating Chrome, Sir')
