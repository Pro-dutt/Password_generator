const MAX = 52;

class File {
  createFile(temp) {
    const input = temp;
    const strFile = prompt("Enter name of the file (--filename.txt--):");
    const fileContent = temp + "\n";
    const blob = new Blob([fileContent], { type: "text/plain" });
    const url = URL.createObjectURL(blob);
    const link = document.createElement("a");
    link.href = url;
    link.download = strFile;
    link.click();
  }
}

class Random {
  stringGen(size) {
    const alphabet = [
      "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o",
      "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z",
      "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O",
      "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"
    ];
    let res = "";
    for (let i = 0; i < size; i++) {
      res += alphabet[Math.floor(Math.random() * MAX)];
    }
    return res;
  }

  randomNum(size) {
    const numbers = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9];
    const res = [];
    for (let i = 0; i < size; i++) {
      res[i] = numbers[Math.floor(Math.random() * 10)];
    }
    return res;
  }

  printNum(rand) {
    for (let j = 0; j < rand.length; j++) {
      console.log(rand[j] + " ");
    }
    return rand;
  }

  spCharGen(size) {
    const spChars = ["@", "#", "$", "^", "&", "*", "!", "~", "/", "*", "-"];
    let res = "";
    for (let k = 0; k < size; k++) {
      res += spChars[Math.floor(Math.random() * spChars.length)];
    }
    return res;
  }

  convertToString(rand) {
    let res = "";
    if (rand.length > 0) {
      for (let i = 0; i < rand.length; i++) {
        res += rand[i];
      }
    }
    return res;
  }

  finalConv(res, size) {
    let finalStr = "";
    for (let i = 0; i < size; i++) {
      finalStr += res[Math.floor(Math.random() * res.length)];
    }
    return finalStr;
  }
}

class Check {
  isTrue(ch) {
    if (ch === "y" || ch === "Y") {
      return true;
    } else if (ch === "n" || ch === "N") {
      return false;
    } else {
      console.log("\nEnter (y/n) in console!");
      return false;
    }
  }

  checkCase(num) {
    if (num > 0 && num < 8) {
      return true;
    } else {
      return false;
    }
  }

  ask() {
    const c = prompt("\nDo you wish to create a txt file (y/n):");
    if (c === "y" || c === "Y") {
      return true;
    } else if (c === "n" || c === "N") {
      return false;
    } else {
      console.log("\nEnter (y/n) in the console:");
      return false;
    }
  }
}

function main() {
  const r = new Random();
  const f = new File();
  const c = new Check();
  let generatedPassword;
  let str1, str2, str3;
  let size, ch;
  let chc = "y";

  console.log("Welcome to password generator!");
  console.log("");
  console.log("The options are:");
  console.log("1. String Generator");
  console.log("2. Number generator");
  console.log("3. Symbol generator");
  console.log("4. String, Symbol generator");
  console.log("5. String, Number generator");
  console.log("6. Character, Number generator");
  console.log("7. String, Character, Number generator");

  ch = parseInt(prompt("Enter your option:"));

  if (c.checkCase(ch) === true) {
    size = parseInt(prompt("Enter the size of the password:"));
  } else {
    console.log("Case not valid");
    return;
  }

  const randomNumbers = r.randomNum(size);
  str1 = r.stringGen(size);
  str2 = r.convertToString(randomNumbers, size);
  str3 = r.spCharGen(size);
  const str4 = str1 + str3;
  const str5 = str1 + str2;
  const str6 = str3 + str2;
  const str7 = str1 + str2 + str3;

  do {
    switch (ch) {
      case 1:
        generatedPassword = r.stringGen(size);
        console.log("\nThe Random string is: " + generatedPassword);
        if (c.ask() === true) {
          f.createFile(generatedPassword);
        }
        break;

      case 2:
        generatedPassword = r.convertToString(randomNumbers, size);
        console.log("\nRandom numbers are: " + generatedPassword);
        if (c.ask() === true) {
          f.createFile(generatedPassword);
        }
        break;

      case 3:
        generatedPassword = r.spCharGen(size);
        console.log("\nRandom symbols are: " + generatedPassword);
        if (c.ask() === true) {
          f.createFile(generatedPassword);
        }
        break;

      case 4:
        generatedPassword = r.finalConv(str4, size);
        console.log("\nRandom string, symbol are: " + generatedPassword);
        if (c.ask() === true) {
          f.createFile(generatedPassword);
        }
        break;

      case 5:
        generatedPassword = r.finalConv(str5, size);
        console.log("\nRandom string, number are: " + generatedPassword);
        if (c.ask() === true) {
          f.createFile(generatedPassword);
        }
        break;

      case 6:
        generatedPassword = r.finalConv(str6, size);
        console.log("\nRandom symbol, number are: " + generatedPassword);
        if (c.ask() === true) {
          f.createFile(generatedPassword);
        }
        break;

      case 7:
        generatedPassword = r.finalConv(str7, size);
        console.log("\nRandom string, symbol, numbers are: " + generatedPassword);
        if (c.ask() === true) {
          f.createFile(generatedPassword);
        }
        break;

      default:
        console.log("\nThe case is not invalid");
        break;
    }

    chc = prompt("\nDo you wish to continue (y/n):");
  } while (c.isTrue(chc) === true);
}

main();
