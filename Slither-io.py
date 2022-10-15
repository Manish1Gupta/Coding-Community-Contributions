import pygame, sys
import time
import random

pygame.init()

window_ht = 600
window_wt = 1000

black = (0, 0 , 0)
white = (255, 255, 255)
red = (255, 0, 0)
blue = (0, 255, 0)
green = (0, 0 ,255)

window = pygame.display.set_mode([window_wt,window_ht])
pygame.display.set_caption('Slither.eat : The Snake Game')

screen = pygame.display.get_surface()

font = pygame.font.SysFont(None, 25, bold = True)

def myquit():
    pygame.quit()
    sys.exit(0)


clock = pygame.time.Clock()
FPS = 5                               # frame rate for  refreshing screen
blockSize = 20
noPixel = 0

def snake(blocksize, snakelist):
    for size in snakelist:
        pygame.draw.rect(screen, black, [size[0]+5,size[1],blocksize,blocksize])

def message_to_screen(msg, color):
    screen_text = font.render(msg, True, color)
    screen.blit(screen_text, [window_wt/2, window_ht/2])


def gameLoop():
    gameExit = False
    gameOver = False

    lead_x = window_wt/2
    lead_y = window_ht/2

    change_pixels_of_x = 0
    change_pixels_of_y = 0

    snakelist = []
    snakeLength = 1

    randomAppleX = round(random.randrange(0, window_wt-blockSize)/10.0)*10.0
    randomAppleY = round(random.randrange(0, window_ht-blockSize)/10.0)*10.0 

    while not gameExit:

        while gameOver == True:
            screen.fill(blue)
            message_to_screen("Game Over, press c to play again or q to quit", red)
            pygame.display.update()

            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    gameOver=False
                    gameExit=True

                if event.type == pygame.KEYDOWN:
                    if event.key == pygame.K_q:
                        gameExit = True
                        gameOver = False
                    if event.key == pygame.K_c:
                        gameLoop()
#Logic 1       
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                gameExit=True

            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    myquit()
                leftArrow = event.key == pygame.K_LEFT
                rightArrow = event.key == pygame.K_RIGHT
                upArrow = event.key == pygame.K_UP
                downArrow = event.key == pygame.K_DOWN

                if leftArrow:
                    change_pixels_of_x = -blockSize
                    change_pixels_of_y = noPixel
                elif rightArrow:
                    change_pixels_of_x = blockSize
                    change_pixels_of_y = noPixel
                elif upArrow:
                    change_pixels_of_x = noPixel
                    change_pixels_of_y = -blockSize
                else:
                    change_pixels_of_x = noPixel
                    change_pixels_of_y = blockSize
#Logic 2
        if lead_x >= window_wt or lead_x < 0 or lead_y >= window_ht or lead_y < 0:
                gameOver = True
        
        lead_x += change_pixels_of_x
        lead_y += change_pixels_of_y

        screen.fill(blue)

        AppleThickness = 20


#Logic 3
        pygame.draw.rect(screen, red, [randomAppleX,randomAppleY,AppleThickness,AppleThickness])

        allspritelist = []
        allspritelist.append(lead_x)
        allspritelist.append(lead_y)
        snakelist.append(allspritelist)

        if len(snakelist) > snakeLength:
            del snakelist[0]

        for eachSegment in snakelist [:-1]:
            if eachSegment == allspritelist:
                gameOver = True

#Logic 4
        snake(blockSize, snakelist)

        pygame.display.update()

#Logic 5
        if lead_x >= randomAppleX and lead_x <= randomAppleX + AppleThickness:
            if lead_y >= randomAppleY and lead_y <= randomAppleY +  AppleThickness:
                randomAppleX = round(random.randrange(0, window_wt-blockSize)/10.0)*10.0
                randomAppleY = round(random.randrange(0, window_ht-blockSize)/10.0)*10.0 
                snakeLength += 1

        clock.tick(FPS)

    
    pygame.quit()
    quit()

gameLoop()  
                

