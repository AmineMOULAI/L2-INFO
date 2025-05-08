def word_8(filename : str):
    with open(filename, "r", encoding="utf8") as f:
        words = f.read().split() 
        f.close()
    return words

def diff(m1, m2 : str) -> str:
    d = ""
    for i in range(len(m1)):
        d += chr((abs(ord(m1[i]) - ord(m2[i])) + 65))
    return d



t = word_8("dictionnaire_larousse.txt")

w8 = []
for i in range(len(t)):
    if len(t[i]) == 8:
        w8.append(t[i])

#print(w8)

def find_words(words : list[str], d : str) -> tuple:
    for i in range(10):
        for j in range(i + 1, 10):
            print(diff(words[i], words[j]))
            if diff(words[i], words[j]) == d:
                return words[i], words[j]
    return -1, -1

m1 = "LHRUTQGA"
m2 = "IDGFCQGA"
d = diff(m1, m2)
print(d)
res = find_words(w8, d)
print(res)