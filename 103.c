from reportlab.lib.pagesizes import A4
from reportlab.pdfgen import canvas
from reportlab.pdfbase.ttfonts import TTFont
from reportlab.pdfbase import pdfmetrics
import requests
import os

# Download the Fairfax HD font
font_url = "https://github.com/kreativekorp/open-relay/raw/refs/heads/master/FairfaxHD/FairfaxHD.ttf"
font_path = "/mnt/data/FairfaxHD.ttf"

if not os.path.exists(font_path):
    with requests.get(font_url, stream=True) as r:
        with open(font_path, 'wb') as f:
            f.write(r.content)

# Register the Fairfax HD font
pdfmetrics.registerFont(TTFont('FairfaxHD', font_path))

# Create a PDF
pdf_path = "/mnt/data/Multiplex_Channel_Chart.pdf"
c = canvas.Canvas(pdf_path, pagesize=A4)
c.setFont("FairfaxHD", 10)
width, height = A4

# Title
c.setFont("FairfaxHD", 16)
c.drawString(50, height - 50, "Multiplex Channel Chart")
c.setFont("FairfaxHD", 10)

# Data to write
data = {
    "SCTV Mux": [
        ("SCTV", 23, 10, "N/A"),
        ("Indosiar", 24, 11, "N/A"),
        ("Moji", 35, 26, "N/A"),
        ("Mentari TV", 36, "N/A", "N/A"),
        ("Kompas TV", 11, 15, "N/A")
    ],
    "RTV Mux": [
        ("RTV", 25, 35, "N/A"),
        ("Salin TV", 100, "N/A", "N/A"),
        ("Tempel TV", 101, "N/A", "N/A"),
        ("Garuda TV", 17, 45, "N/A")
    ],
    "Metro TV Mux": [
        ("Metro TV", 22, 7, "N/A"),
        ("Magna Channel", 38, "N/A", "N/A"),
        ("BN Channel", 39, "N/A", "N/A"),
        ("Jawa Pos TV", 45, "N/A", "N/A"),
        ("MDTV", 16, 5, "N/A")
    ],
    "tvOne Mux": [
        ("tvOne", 27, 14, "N/A"),
        ("ANTV", 26, 13, "N/A"),
        ("VTV", 37, "N/A", "N/A"),
        ("Jagantara TV", 77, "N/A", "N/A")
    ],
    "RCTI Mux": [
        ("RCTI", 28, "N/A", "N/A"),
        ("MNCTV", 29, "N/A", "N/A"),
        ("GTV", 30, 53, "N/A"),
        ("iNews", 31, 65, "N/A")
    ],
    "Trans TV Mux": [
        ("Trans TV", 20, 9, "N/A"),
        ("Trans 7", 21, 8, "N/A"),
        ("CNN Indonesia", 19, "N/A", "N/A"),
        ("CNBC Indonesia", 18, "N/A", "N/A")
    ],
    "Nusantara TV Mux": [
        ("Nusantara TV", 32, "N/A", "N/A"),
        ("Harum TV", 33, "N/A", "N/A"),
        ("Gold TV", 34, "N/A", "N/A"),
        ("Bhineka TV", "N/A", "N/A", "N/A")
    ],
    "Hello! Project Mux": [
        ("Morning Musume", "N/A", "N/A", 1),
        ("Morning Musume '14-'25", "N/A", "N/A", 2),
        ("S/mileage", "N/A", "N/A", 3),
        ("ANGERME", "N/A", "N/A", 4),
        ("Juice=Juice", "N/A", "N/A", 5),
        ("Country Girls", "N/A", "N/A", 6),
        ("Kobushi Factory", "N/A", "N/A", 7),
        ("Tsubaki Factory", "N/A", "N/A", 8),
        ("BEYOOOOONDS", "N/A", "N/A", 9),
        ("OCHA NORMA", "N/A", "N/A", 10),
        ("Rosy Chronicle", "N/A", "N/A", 11)
    ],
    "TVRI Mux": [
        ("TVRI Nasional", 1, 16, "N/A"),
        ("TVRI Daerah", 2, "N/A", "N/A"),
        ("TVRI World", 3, "N/A", "N/A"),
        ("TVRI Sport", 4, "N/A", "N/A"),
        ("BTV", "N/A", 1, "N/A")
    ]
}

# Positioning
y = height - 80
for mux, channels in data.items():
    c.setFont("FairfaxHD", 12)
    c.drawString(50, y, mux)
    y -= 15
    c.setFont("FairfaxHD", 10)
    c.drawString(60, y, "Channel | Virtual | First Media | Hello! Project")
    y -= 12
    for ch in channels:
        c.drawString(60, y, f"{ch[0]} | {ch[1]} | {ch[2]} | {ch[3]}")
        y -= 12
        if y < 100:
            c.showPage()
            y = height - 50
            c.setFont("FairfaxHD", 10)

c.save()
pdf_path
