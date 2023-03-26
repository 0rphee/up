class hpAPI():
    def __init__(self):
        print("Objeto creado")
        self.__url_base = "https://hp-api.onrender.com/api"
    def personajes(self) -> list:
        import requests
        response = requests.get(url=f"{self.__url_base}/characters")
        return response.json()

def main():
    api = hpAPI()
    api.personajes()

if __name__ == "__main__": 
    main()
