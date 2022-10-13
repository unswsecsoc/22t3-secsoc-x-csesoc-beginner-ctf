from flask import Flask, request

app = Flask(__name__)

@app.route("/")
def challenge():
    return_val = ""

    if request.args.get("option") is None:
        return_val = """
            <h1>Beware Hackers</h1>
            <p>This website has secured its secrets with URL parameter based authentication, you never stood a chance</p>
            
            <!-- TODO: Figure out how to defend against the following  -->
            <!-- https://github.com/Sh1Yo/x8  -->
            <!-- https://raw.githubusercontent.com/gwen001/SecLists/master/mine/burp-parameter-names.txt -->

        """
    else:
        return_val = "<p>BEGINNER{param3t3r_M1ning_1923hfe}</p>"

    return return_val

