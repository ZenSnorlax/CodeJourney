from flask import Flask

app = Flask(__name__)


@app.route("/")
def index():
    return "Hello World"


@app.route("/archives")
def archives():
    return "archives"


@app.route("/2024/8/hello")
def page0():
    return "index"
