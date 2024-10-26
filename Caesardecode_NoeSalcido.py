#Caesar Cipher - www.101computing.net/caesar-cipher
# Tarea de decodificacion en Cesar de Noé Fernando Salcido Ochoa

cipher = "N qtaj uwtlwfrrnsl zxnsl Udymts"
i = 0
cipherlist = []
for x in cipher.lower():
    cipherlist.append(ord(x))

for x in cipherlist:
    if x != 32:
        x = ((x - 102) % 26) + 97
        cipherlist[i] = chr(x)
    else:
        cipherlist[i] = chr(x)
    i += 1

print("".join(cipherlist))

#Complete the code below to decode this cipher using a 5-character right shift