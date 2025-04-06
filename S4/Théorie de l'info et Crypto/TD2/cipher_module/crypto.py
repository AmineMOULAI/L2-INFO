from collections import Counter

def frequency_analysis(m : str):
    print(Counter(m.replace(" ","")))

def _ic(m :str) -> float:
    t = 0.
    l = len(m)
    frequency = Counter(m)
    for f in frequency:
        t += (frequency[f]*(frequency[f] - 1)) / (l * (l - 1))
    return t

def dech_vigenere(message, key):
    message_crypte = []
    key_length = len(key)
    i = 0
    for m in message:
        nouveau_car = chr(((ord(m) - 65 - ord(key[i])- 65) % 26) + 65)
        message_crypte.append(nouveau_car)
        i = (i + 1) % key_length
    print("".join(message_crypte))

'''
frequency_analysis("AHOXUREZZOSHIPSDHHDSHFLCPQAFPAMMDUF")
i = _ic("AHOXUREZZOSHIPSDHHDSHFLCPQAFPAMMDUF")
i1 = _ic("BTEDHGHAOSRLNRQMLVXCAKWVGSGATSRICOI")
i2 = _ic("CWOQKPUEGEJKHHTGOGPVGUVWPRGWRNWUUWT")
print("{:.4f}, {:.4f}, {:.4f}".format(i, i1, i2))
'''

m1 = "EOJRVWVWXSKDGHULOWJHXDRUMFRQVVVVVCDPXIEETASRNZRJKOEGXOWITWIHWIEKHADHXGKGXAFQMSIGTBJOTQCDLGVVNDVUBSLUXOCDLWVQGSVWMCLWESWIHFKGXQVWMSTOTGJHXGKGXZVPISTKXFUHFCEWXF"



for i in range(4):
    frequency_analysis(m1[i:len(m1):4])

print(chr((ord('X') - 65 - ord('E') - 65) % 26 + 65))
print(chr((ord('S') - 65 - ord('E') - 65) % 26 + 65))
print(chr((ord('V') - 65 - ord('E') - 65) % 26 + 65))
print(chr((ord('H') - 65 - ord('E') - 65) % 26 + 65))

dech_vigenere(m1, "TORD")
