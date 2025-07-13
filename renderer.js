const { exec } = require("child_process");
const fs = require("fs");
const path = require("path");

window.addEventListener("DOMContentLoaded", () => {
  const runButton = document.getElementById("runBtn");
  const commandInput = document.getElementById("commandInput");
  const outputBox = document.getElementById("output");

  // Set the initial welcome/help message
  outputBox.textContent = `
📁 Welcome to File System Simulator!

Available Commands:
> mkdir <name>  - Create a directory
> cd <name>     - Change directory
> cd ..         - Go back to parent directory
> ls            - List current directory contents
> pwd           - Show current working path

Start typing commands above ⤴ and click Run!
`;

  runButton.addEventListener("click", () => {
    const command = commandInput.value.trim();
    if (!command) return;

    // Append command to input.txt
    const inputPath = path.join(__dirname, "backend", "input.txt");
    const outputPath = path.join(__dirname, "backend", "output.txt");
    fs.appendFileSync(inputPath, command + "\n");

    // Run the backend C++ executable
    const exePath = path.join(__dirname, "backend", "fs.exe");
    const execCommand = `"${exePath}" < "${inputPath}" > "${outputPath}"`;

    exec(execCommand, (error, stdout, stderr) => {
      if (error) {
        outputBox.textContent = `⚠️ Error: ${error.message}`;
        return;
      }
      if (stderr) {
        outputBox.textContent = `⚠️ StdErr: ${stderr}`;
        return;
      }

      try {
        const result = fs.readFileSync(outputPath, "utf-8");
        outputBox.textContent = result;
      } catch (e) {
        outputBox.textContent = "❌ Failed to read output.txt";
      }
    });

    // Clear the input box
    commandInput.value = "";
  });
});
