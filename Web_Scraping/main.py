from bs4 import BeautifulSoup

#read practice.html as a variable
with open('Coding-Community-Contributions\Web_Scraping\practice.html', 'r') as html_file: 
    #display practice.html
    content=html_file.read() 
    
    #print(content)

    #create instance of the BeautifulSoup class
    soup = BeautifulSoup(content,'lxml') 

    #Prettifies the html file
    #print(soup.prettify())

    #finds the first occurence of the given tag
    #tags = soup.find('h1')

    #finds all the occurences of the given tag
    tags = soup.find_all('div',class_='card')
    #print(tags)

    for tag in tags:
        author_name=tag.p.text.split('-')[-1]
        button_name=tag.a.text
        print(f"{button_name} corresponds to quote given by {author_name}")
