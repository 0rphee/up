from typing import List


def celsiusAFarenheit(celsius: float) -> float: 
    return (celsius * 9 / 5) + 32


def printBeffo(usuario: str, beffo: str, *amigos: List[str]):
    print(f"""
Hola {usuario}
Tu mejor amigo es {beffo}
Y tus demás amigos son: """)
    for amigo in amigos:
        print(f"\t{amigo}")


def main():
    print(celsiusAFarenheit(95))
    printBeffo("ro", "pancho", "panfleto", "pedrito")


if __name__ == "__main__":
    main()
