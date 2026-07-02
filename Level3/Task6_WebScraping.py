import requests
from bs4 import BeautifulSoup

def scrape_books(url):
    response = requests.get(url)
    response.encoding = 'utf-8'  
    
    if response.status_code != 200:
        print("Failed to fetch the page!")
        return []
    
    soup = BeautifulSoup(response.text, "html.parser")
    books = soup.find_all("article", class_="product_pod")
    
    results = []
    for book in books:
        title = book.h3.a["title"]
        price = book.find("p", class_="price_color").text
        rating = book.find("p", class_="star-rating")["class"][1]
        
        results.append({
            "title": title,
            "price": price,
            "rating": rating
        })
    
    return results

def display_books(books):
    print(f"\n{'No.':<5} {'Title':<50} {'Price':<10} {'Rating'}")
    print("-" * 75)
    
    for i, book in enumerate(books, 1):
        print(f"{i:<5} {book['title']:<50} {book['price']:<10} {book['rating']}")

def main():
    url = "https://books.toscrape.com"
    print(f"Scraping: {url}\n")
    
    books = scrape_books(url)
    
    if books:
        display_books(books)
        print(f"\nTotal books found: {len(books)}")
    else:
        print("No books found!")

main()