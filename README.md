# Coffee-box
![imagename](https://res.cloudinary.com/edmonddantes/image/upload/v1617100114/Screenshot_from_2021-03-30_13-27-18_mbizoj.png)
## About
**Сoffee-box** is a console application written in C++ that simulates a coffee machine.The machine monitors the number of cups and money, the rest of the materials within the project we do not control.

With **Сoffee-box** you can:
* choose and order coffee
* change prices of coffee
* put money on balance
* add your PIN for service
* check and withdraw money out of the coffee machine
* check and refill cups in the machine
## What's inside
The project was implemented to consolidate the passed material on functional programming. Written using functions in C ++.
## Installation
### Step 1. Install C/C++ compiler and related tools
If you are using Fedora, Red Hat, CentOS, or Scientific Linux, use the following yum command to install GNU c/c++ compiler:
```
 yum groupinstall 'Development Tools'
```
If you are using Debian or Ubuntu Linux, type the following apt-get command to install GNU c/c++ compiler:
```
$ sudo apt-get update
$ sudo apt-get install build-essential manpages-dev
```
### Step 2. Verify installation

Type the following command to display the version number and location of the compiler on Linux:
```
$ whereis gcc
$ which gcc
$ gcc --version
```
Sample outputs:
![imagename](https://res.cloudinary.com/edmonddantes/image/upload/v1617098581/Screenshot_from_2021-03-30_13-00-18_qwymiy.png)

### Step 3. Clone the current repository
```
 $ git clone https://github.com/zadziarnouksi-taras/coffee-box.git
```
If you don't have a **GIT**, then install it first:
```
# apt-get install git
```
### Step 4. Compile and Run C++ program on Linux
To compile this program, enter:
```
g++ coffeeMachine.cpp -o coffeeMachine
```
OR
```
make cofeeMachine
```
To run this program, type:

```
./coffeeMachine
```


## Configuration
To change to your values, correct at the beginning of the program:
```C++
#define ESPRESSO_PRICE X
#define CAPPUCCINO_PRICE X
#define LATTE_PRICE X
#define PIN XXXX
```

## Authors
**Taras Zadziarnouski**. Send me message to [Gmail](mailto:taras.zadziarnouski@gmail.com "Gmail"). Add me to [LinkedIn](https://www.linkedin.com/in/taras-zadziarnouski-b6205a206/ "LinkedIn"). Follow me to [Instagram](https://t.me/taraszadziarnouski "Instagram").

**Dzmitry Litvinau**. Send a message and follow to Dzmitry on [GitHub](https://github.com/dzmitri-litvinov "GitHub").

### Our mentor:
**Vadzim Alkhimionak**. Send a message and follow to Vadzim on [GitHub](https://github.com/VadzimAlkhimionak "GitHub").


