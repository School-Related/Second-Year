import os
from selenium import webdriver
from selenium.webdriver.common.by import By
import time

# os.environ['PATH'] += r"C:/SeleniumDrivers"
driver = webdriver.Chrome()
driver.get("https://phptravels.com/demo/")


# driver.implicitly_wait(30)
#maximize the window size  
driver.maximize_window()  
#delete the cookies  
driver.delete_all_cookies()  


first_name = driver.find_element(By.NAME, 'first_name')
first_name.send_keys('Sourab')
time.sleep(2)
last_name = driver.find_element(By.NAME, 'last_name')
last_name.send_keys('Karad')
time.sleep(2)
biss_name = driver.find_element(By.NAME, 'business_name')
biss_name.send_keys('Kuch bhi')
time.sleep(2)
email = driver.find_element(By.NAME, 'email')
email.send_keys('soemthing@gmail.com')
time.sleep(2)
number_1 = driver.find_element(By.ID, 'numb1')
number_2 = driver.find_element(By.ID, 'numb2')
time.sleep(2)
# take text from number 1 and 2
num1 = number_1.text
num2 = number_2.text

ans = int(num1) - int(num2)
print(num1, num2, ans)

answer = driver.find_element(By.ID, 'number')
answer.send_keys(ans)
time.sleep(2)

submit_button = driver.find_element(By.ID, 'demo')

submit_button.click()

time.sleep(2)

tick_mark = driver.find_element(By.ID, 'colored')
if tick_mark.is_displayed():
    print('Test case passed')
else:
    print('Test case failed')