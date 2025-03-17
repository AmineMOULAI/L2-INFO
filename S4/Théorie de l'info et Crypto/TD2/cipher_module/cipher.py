'''
    * frequency()
    * reverse()
    * system_resolution()

'''

from collections import Counter
from math import gcd

M = 26
def frequency(m : str):
    print(Counter(m.replace(" ", "")))

def reverse(a : int, mod : int) -> int:
    return next((i for i in range(1, mod) if (a * i) % mod == 1), -1)

def normalization(n : int) -> int: return (n + M*M) % M

def system_resolution(cl1, cl2, ch1, ch2, M : int) -> tuple():
    dcl = normalization(cl1 - cl2)
    dch = normalization(ch1 - ch2)
    d = gcd(dcl, M)
    if d == 1:
        r = reverse(dcl, M)
        a = normalization(r * (ch1 - ch2))
        b = normalization(ch1 - a * cl1)
        return (a, b)
    else:
        if(dch % d) == 0:
            dcl //= d
            dch //= d
            M //= d
            r = reverse(dcl, M)
            a = normalization(r * dch)
            nba = [(a + M*i) % (M * d) for i in range(2)]
            for i in nba:
                if gcd(i, M*d) == 1:
                    a = i
                    b = normalization(ch1 - a * cl1)
                    return (a, b)

        else:
            return (-1, -1)
         


print(system_resolution(4, 0, 3, 5, M))

def affine_decipher(ch : str, a, b, M : int):
    alphabet = {chr(i): i - ord('a') for i in range(ord('a'), ord('z') + 1)}
    m = ''
    for i in ch:
        m += chr(normalization((a * (alphabet[i] - b))))
    print(m)

def vigenere_cipher(message, key : str) -> str:
    ciphertext = ""
    l = len(key)
    i = 0
    for m in message:
        c = chr((ord(m) - 65 + ord(key[i]) - 65) % 26 + 65) 
        ciphertext += c
        i = (i + 1) % l
    return ciphertext

#print(vigenere("CETEXAMENESTFACILE", "KEY"))
def find_key(text, ciphertext : str):
    l = len(text)
    for i in range(l):
        print(chr(abs(ord(text[i]) - ord(ciphertext[i])) % 26 + 65), end="")

#find_key("REUTILISER", "TPYYKWMXGC")

def vigenere_decipher(ciphertext, key : str) -> str:
    text = ""
    l = len(key)
    i = 0
    for m in ciphertext:
        c = chr(((ord(m) - 65) - (ord(key[i]) - 65)) % 26 + 65) 
        text += c
        i = (i + 1) % l
    return text

print(vigenere_decipher("XZYXGEIXUFVQCMSSPPZTKP", "KEY"))