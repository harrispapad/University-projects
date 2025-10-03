# Software Engineering

This directory contains the course project for Software Engineering (2024-2025), implementing a full-stack web application with RESTful API and CLI client.

**Partners:** Stroubakou Eirini, Striftis Georgios, Papangeli Dimitra, Sanidas Anastasios

## Contents

### Project Overview

A complete web application featuring:

- Express.js backend with MySQL database
- Modern web frontend
- Command-line interface (CLI) client
- User authentication and authorization
- Admin functionality
- Time tracking features

### Components

#### Back-end (`back-end/`)

Node.js/Express server with:

- RESTful API routes (authentication, admin, time tracking)
- MySQL database integration
- JWT-based authentication middleware
- Session and cookie management
- File upload handling

#### Front-end (`front-end/`)

Web-based user interface for the application.

#### CLI Client (`cli-client/`)

Command-line interface for interacting with the API.

- Executable: `se2415`
- Built with Commander.js

#### Documentation (`documentation/`)

Project documentation, API specifications, and design documents.

#### AI Log (`ai-log/`)

Development logs and AI-assisted development notes.

### Technologies Used

- **Backend**: Node.js, Express.js
- **Database**: MySQL
- **Authentication**: JWT (JSON Web Tokens), bcrypt
- **Frontend**: HTML/CSS/JavaScript
- **CLI**: Commander.js
- **Data Export**: JSON to CSV conversion
- **Environment**: dotenv for configuration
