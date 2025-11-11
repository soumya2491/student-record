from flask import Flask, request, jsonify
import subprocess

app = Flask(__name__)

@app.route('/')
def home():
    return 'Student Record System Backend is running!'

@app.route('/add_student', methods=['POST'])
def add_student():
    roll = request.form['roll']
    name = request.form['name']
    marks = request.form['marks']

    # Path to the compiled C program inside c-logic folder
    result = subprocess.run(['./c-logic/studentApp', roll, name, marks], capture_output=True, text=True)

    return jsonify({
        'output': result.stdout,
        'error': result.stderr
    })

if __name__ == '__main__':
    app.run(debug=True)
