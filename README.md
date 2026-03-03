# SHA-256 Password Cracker

This is a small C program that checks whether a given password matches a SHA-256 hash.

The program reads possible passwords from standard input, hashes each one using OpenSSL, and compares the result to a target hash provided as a command-line argument.  
If a direct match is not found, it also tries flipping the case of one letter at a time.

I built this project to practice working with cryptographic hashing, command-line arguments, and low-level string handling in C.

---

## What it does

- Computes SHA-256 hashes using OpenSSL  
- Accepts a target hash from the command line  
- Reads candidate passwords from stdin  
- Tries simple case variations  
- Stops as soon as a match is found  

---

## Build

```
gcc -O2 -Wall pwcrack.c -o pwcrack -lcrypto
```

---

## Run

```
./pwcrack <expected_sha256_hash>
```

Example:

```
echo -e "password\nPassword\n123456" | ./pwcrack <hash_here>
```
