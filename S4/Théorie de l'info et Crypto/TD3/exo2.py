def diff(w1, w2 : str) -> str:
    d = ""
    for i in range(len(w1)):
        l = abs(ord(w1[i]) - 97 - ord(w2[i]) - 97)
        d += chr(l % 26 + 97) 
    return d

'''def file_length(fname):
    l = 0
    with open(fname, "r", encoding="utf8") as f:
        for word in f:
            l += 1
    return l'''


def find_words(fname : str, s : str) -> tuple:
    with open(fname, "r", encoding="utf8") as f:
        lines = f.readlines() 
        for i, w in enumerate(lines):
            w = w.strip()
            while len(lines[i + 1]) == 7:
                d = diff(w, lines[i + 1])
                if d == s:
                    return (w, lines[i + 1])
                i += 1
            

    f.close()

'''s1, s2 = "amine", "ahmed"
print(diff(s1, s2))
find_words("dictionnaire-francais.txt")'''

print(file_length("dictionnaire-francais.txt"))
