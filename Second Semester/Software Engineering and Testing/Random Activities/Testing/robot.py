import os
from selenium import webdriver
from selenium.webdriver.common.by import By
import time

# os.environ['PATH'] += r"C:/SeleniumDrivers"
driver = webdriver.Chrome()
driver.get("https://www.google.com/recaptcha/api2/demo")


# driver.implicitly_wait(30)
#maximize the window size  
driver.maximize_window()  
#delete the cookies  
driver.delete_all_cookies()  

time.sleep(2)

try: 
    button = driver.find_element(By.CLASS_NAME, 'recaptcha-checkbox-checkmark')
    button.click()

    time.sleep(3)

    submit = driver.find_element(By.ID, 'recaptcha-demo-submit')
    submit.click()

    time.sleep(3)

    success = driver.find_element(By.CLASS_NAME, 'recaptcha-success')
    if success.is_displayed():
        print('Test case passed')
    else:
        print('Test case failed')
except:
    print('Test case failed')