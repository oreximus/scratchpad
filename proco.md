# Airline Management System - Modern & User-Centric Implementation

## Frontend Implementation

### 1. Modern UI Structure

**HTML (index.html)**

```html
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>SkyVoyage - Modern Airline Management</title>
    <link rel="stylesheet" href="css/main.css" />
    <link
      rel="stylesheet"
      href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.0.0/css/all.min.css"
    />
  </head>
  <body>
    <!-- Animated Navigation Bar -->
    <nav class="glass-nav">
      <div class="logo">
        <i class="fas fa-plane"></i>
        <span>SkyVoyage</span>
      </div>
      <div class="nav-links">
        <a href="#" class="active">Home</a>
        <a href="#">Book</a>
        <a href="#">My Trips</a>
        <a href="#">Offers</a>
        <div class="user-dropdown">
          <img src="images/user-avatar.png" alt="User" class="user-avatar" />
          <div class="dropdown-content">
            <a href="#">Profile</a>
            <a href="#">Settings</a>
            <a href="#">Logout</a>
          </div>
        </div>
      </div>
      <div class="hamburger">
        <i class="fas fa-bars"></i>
      </div>
    </nav>

    <!-- Hero Section with Search -->
    <section class="hero">
      <div class="hero-content">
        <h1>Where will you fly today?</h1>
        <div class="search-container">
          <div class="search-tabs">
            <button class="active">Round Trip</button>
            <button>One Way</button>
            <button>Multi-City</button>
          </div>
          <div class="search-form">
            <div class="input-group">
              <label>From</label>
              <input
                type="text"
                placeholder="City or Airport"
                id="origin"
                autocomplete="off"
              />
              <div class="airport-suggestions" id="origin-suggestions"></div>
            </div>
            <button class="swap-btn">
              <i class="fas fa-exchange-alt"></i>
            </button>
            <div class="input-group">
              <label>To</label>
              <input
                type="text"
                placeholder="City or Airport"
                id="destination"
                autocomplete="off"
              />
              <div
                class="airport-suggestions"
                id="destination-suggestions"
              ></div>
            </div>
            <div class="input-group">
              <label>Departure</label>
              <input type="date" id="departure-date" />
            </div>
            <div class="input-group">
              <label>Return</label>
              <input type="date" id="return-date" />
            </div>
            <div class="input-group">
              <label>Travelers</label>
              <div class="travelers-select">
                <span id="travelers-display">1 Adult</span>
                <i class="fas fa-chevron-down"></i>
                <div class="travelers-dropdown">
                  <div class="traveler-type">
                    <span>Adults</span>
                    <div class="counter">
                      <button class="decrement">-</button>
                      <span class="count">1</span>
                      <button class="increment">+</button>
                    </div>
                  </div>
                  <div class="traveler-type">
                    <span>Children</span>
                    <div class="counter">
                      <button class="decrement">-</button>
                      <span class="count">0</span>
                      <button class="increment">+</button>
                    </div>
                  </div>
                  <div class="traveler-type">
                    <span>Infants</span>
                    <div class="counter">
                      <button class="decrement">-</button>
                      <span class="count">0</span>
                      <button class="increment">+</button>
                    </div>
                  </div>
                  <div class="traveler-type">
                    <span>Class</span>
                    <select>
                      <option>Economy</option>
                      <option>Premium Economy</option>
                      <option>Business</option>
                      <option>First Class</option>
                    </select>
                  </div>
                  <button class="apply-btn">Apply</button>
                </div>
              </div>
            </div>
            <button class="search-btn">Search Flights</button>
          </div>
        </div>
      </div>
    </section>

    <!-- Personalized Recommendations -->
    <section class="recommendations">
      <h2>Recommended for You</h2>
      <div class="recommendation-cards">
        <!-- Dynamically loaded from JS -->
      </div>
    </section>

    <!-- Flight Search Results (Initially hidden) -->
    <section class="flight-results" id="flight-results">
      <div class="results-header">
        <h2>Available Flights</h2>
        <div class="sort-filter">
          <select id="sort-by">
            <option value="price-asc">Price (Low to High)</option>
            <option value="price-desc">Price (High to Low)</option>
            <option value="duration-asc">Duration (Shortest)</option>
            <option value="departure-asc">Departure (Earliest)</option>
          </select>
          <button class="filter-btn">
            <i class="fas fa-filter"></i> Filters
          </button>
        </div>
      </div>
      <div class="flight-cards" id="flight-cards">
        <!-- Dynamically loaded from JS -->
      </div>
    </section>

    <!-- Booking Modal -->
    <div class="modal" id="booking-modal">
      <div class="modal-content">
        <span class="close-modal">&times;</span>
        <div class="booking-steps">
          <div class="step active" data-step="1">
            <span>1</span>
            <p>Flight Details</p>
          </div>
          <div class="step" data-step="2">
            <span>2</span>
            <p>Passenger Info</p>
          </div>
          <div class="step" data-step="3">
            <span>3</span>
            <p>Seat Selection</p>
          </div>
          <div class="step" data-step="4">
            <span>4</span>
            <p>Payment</p>
          </div>
          <div class="step" data-step="5">
            <span>5</span>
            <p>Confirmation</p>
          </div>
        </div>
        <div class="booking-content">
          <!-- Dynamically loaded based on step -->
        </div>
      </div>
    </div>

    <script src="js/main.js"></script>
  </body>
</html>
```

**CSS (main.css)**

```css
/* Base Styles & Variables */
:root {
  --primary: #2563eb;
  --primary-light: #3b82f6;
  --primary-dark: #1d4ed8;
  --secondary: #10b981;
  --dark: #1e293b;
  --light: #f8fafc;
  --gray: #94a3b8;
  --gray-light: #e2e8f0;
  --danger: #ef4444;
  --warning: #f59e0b;
  --shadow-sm: 0 1px 2px rgba(0, 0, 0, 0.1);
  --shadow-md: 0 4px 6px rgba(0, 0, 0, 0.1);
  --shadow-lg: 0 10px 15px rgba(0, 0, 0, 0.1);
  --transition: all 0.3s ease;
}

* {
  margin: 0;
  padding: 0;
  box-sizing: border-box;
  font-family: "Segoe UI", Tahoma, Geneva, Verdana, sans-serif;
}

body {
  background-color: #f1f5f9;
  color: var(--dark);
  line-height: 1.6;
}

/* Glass Navigation */
.glass-nav {
  display: flex;
  justify-content: space-between;
  align-items: center;
  padding: 1rem 2rem;
  background: rgba(255, 255, 255, 0.8);
  backdrop-filter: blur(10px);
  box-shadow: var(--shadow-sm);
  position: fixed;
  width: 100%;
  top: 0;
  z-index: 1000;
  transition: var(--transition);
}

.glass-nav.scrolled {
  background: rgba(255, 255, 255, 0.95);
  box-shadow: var(--shadow-md);
}

.logo {
  display: flex;
  align-items: center;
  gap: 0.5rem;
  font-size: 1.5rem;
  font-weight: 700;
  color: var(--primary);
}

.logo i {
  font-size: 1.8rem;
}

.nav-links {
  display: flex;
  align-items: center;
  gap: 2rem;
}

.nav-links a {
  text-decoration: none;
  color: var(--dark);
  font-weight: 500;
  transition: var(--transition);
  position: relative;
}

.nav-links a.active,
.nav-links a:hover {
  color: var(--primary);
}

.nav-links a.active::after {
  content: "";
  position: absolute;
  bottom: -0.5rem;
  left: 0;
  width: 100%;
  height: 2px;
  background-color: var(--primary);
}

.user-avatar {
  width: 36px;
  height: 36px;
  border-radius: 50%;
  cursor: pointer;
  transition: var(--transition);
}

.user-avatar:hover {
  transform: scale(1.05);
}

.dropdown-content {
  display: none;
  position: absolute;
  right: 0;
  background-color: white;
  min-width: 160px;
  box-shadow: var(--shadow-md);
  z-index: 1;
  border-radius: 0.5rem;
  overflow: hidden;
}

.dropdown-content a {
  color: var(--dark);
  padding: 0.75rem 1rem;
  text-decoration: none;
  display: block;
  transition: var(--transition);
}

.dropdown-content a:hover {
  background-color: var(--gray-light);
  color: var(--primary);
}

.user-dropdown:hover .dropdown-content {
  display: block;
}

.hamburger {
  display: none;
  font-size: 1.5rem;
  cursor: pointer;
}

/* Hero Section */
.hero {
  height: 100vh;
  background:
    linear-gradient(rgba(0, 0, 0, 0.5), rgba(0, 0, 0, 0.5)),
    url("../images/hero-bg.jpg") no-repeat center center/cover;
  display: flex;
  align-items: center;
  padding: 0 2rem;
  margin-top: 60px;
}

.hero-content {
  max-width: 1200px;
  width: 100%;
  margin: 0 auto;
  color: white;
}

.hero h1 {
  font-size: 3rem;
  margin-bottom: 2rem;
  text-shadow: 2px 2px 4px rgba(0, 0, 0, 0.5);
}

.search-container {
  background: rgba(255, 255, 255, 0.9);
  border-radius: 1rem;
  padding: 1.5rem;
  box-shadow: var(--shadow-lg);
}

.search-tabs {
  display: flex;
  margin-bottom: 1.5rem;
  border-bottom: 1px solid var(--gray-light);
}

.search-tabs button {
  padding: 0.75rem 1.5rem;
  background: none;
  border: none;
  cursor: pointer;
  font-weight: 500;
  color: var(--gray);
  position: relative;
}

.search-tabs button.active {
  color: var(--primary);
}

.search-tabs button.active::after {
  content: "";
  position: absolute;
  bottom: -1px;
  left: 0;
  width: 100%;
  height: 2px;
  background-color: var(--primary);
}

.search-form {
  display: grid;
  grid-template-columns: repeat(auto-fit, minmax(200px, 1fr));
  gap: 1rem;
}

.input-group {
  position: relative;
}

.input-group label {
  display: block;
  margin-bottom: 0.5rem;
  font-weight: 500;
  color: var(--dark);
}

.input-group input,
.input-group select {
  width: 100%;
  padding: 0.75rem;
  border: 1px solid var(--gray-light);
  border-radius: 0.5rem;
  font-size: 1rem;
  transition: var(--transition);
}

.input-group input:focus {
  outline: none;
  border-color: var(--primary);
  box-shadow: 0 0 0 2px rgba(37, 99, 235, 0.2);
}

.airport-suggestions {
  position: absolute;
  width: 100%;
  background: white;
  border: 1px solid var(--gray-light);
  border-radius: 0.5rem;
  max-height: 200px;
  overflow-y: auto;
  z-index: 10;
  display: none;
  box-shadow: var(--shadow-md);
}

.airport-suggestions div {
  padding: 0.75rem;
  cursor: pointer;
  transition: var(--transition);
}

.airport-suggestions div:hover {
  background-color: var(--gray-light);
}

.swap-btn {
  align-self: flex-end;
  background: var(--primary-light);
  color: white;
  border: none;
  width: 40px;
  height: 40px;
  border-radius: 50%;
  cursor: pointer;
  transition: var(--transition);
  display: flex;
  align-items: center;
  justify-content: center;
  margin-bottom: 1.75rem;
}

.swap-btn:hover {
  background: var(--primary-dark);
  transform: rotate(180deg);
}

.travelers-select {
  position: relative;
  cursor: pointer;
}

.travelers-dropdown {
  position: absolute;
  top: 100%;
  left: 0;
  width: 250px;
  background: white;
  border-radius: 0.5rem;
  box-shadow: var(--shadow-md);
  padding: 1rem;
  z-index: 10;
  display: none;
}

.traveler-type {
  display: flex;
  justify-content: space-between;
  align-items: center;
  margin-bottom: 1rem;
}

.counter {
  display: flex;
  align-items: center;
  gap: 0.75rem;
}

.counter button {
  width: 30px;
  height: 30px;
  border-radius: 50%;
  border: 1px solid var(--gray-light);
  background: none;
  cursor: pointer;
  display: flex;
  align-items: center;
  justify-content: center;
  transition: var(--transition);
}

.counter button:hover {
  background: var(--gray-light);
}

.apply-btn {
  width: 100%;
  padding: 0.75rem;
  background: var(--primary);
  color: white;
  border: none;
  border-radius: 0.5rem;
  cursor: pointer;
  font-weight: 500;
  transition: var(--transition);
  margin-top: 0.5rem;
}

.apply-btn:hover {
  background: var(--primary-dark);
}

.search-btn {
  grid-column: 1 / -1;
  padding: 1rem;
  background: var(--primary);
  color: white;
  border: none;
  border-radius: 0.5rem;
  font-size: 1rem;
  font-weight: 500;
  cursor: pointer;
  transition: var(--transition);
  margin-top: 1rem;
}

.search-btn:hover {
  background: var(--primary-dark);
  transform: translateY(-2px);
}

/* Recommendations Section */
.recommendations {
  padding: 4rem 2rem;
  max-width: 1200px;
  margin: 0 auto;
}

.recommendations h2 {
  font-size: 2rem;
  margin-bottom: 2rem;
  color: var(--dark);
}

.recommendation-cards {
  display: grid;
  grid-template-columns: repeat(auto-fill, minmax(280px, 1fr));
  gap: 1.5rem;
}

.recommendation-card {
  background: white;
  border-radius: 1rem;
  overflow: hidden;
  box-shadow: var(--shadow-sm);
  transition: var(--transition);
  cursor: pointer;
}

.recommendation-card:hover {
  transform: translateY(-5px);
  box-shadow: var(--shadow-md);
}

.card-image {
  height: 180px;
  overflow: hidden;
}

.card-image img {
  width: 100%;
  height: 100%;
  object-fit: cover;
  transition: var(--transition);
}

.recommendation-card:hover .card-image img {
  transform: scale(1.05);
}

.card-content {
  padding: 1.5rem;
}

.card-content h3 {
  margin-bottom: 0.5rem;
  color: var(--dark);
}

.card-content p {
  color: var(--gray);
  margin-bottom: 1rem;
}

.card-price {
  font-size: 1.25rem;
  font-weight: 700;
  color: var(--primary);
}

/* Flight Results Section */
.flight-results {
  padding: 2rem;
  max-width: 1200px;
  margin: 0 auto;
  display: none;
}

.results-header {
  display: flex;
  justify-content: space-between;
  align-items: center;
  margin-bottom: 2rem;
}

.results-header h2 {
  font-size: 1.75rem;
  color: var(--dark);
}

.sort-filter {
  display: flex;
  align-items: center;
  gap: 1rem;
}

.sort-filter select {
  padding: 0.5rem 1rem;
  border: 1px solid var(--gray-light);
  border-radius: 0.5rem;
  background: white;
  cursor: pointer;
}

.filter-btn {
  padding: 0.5rem 1rem;
  background: white;
  border: 1px solid var(--gray-light);
  border-radius: 0.5rem;
  cursor: pointer;
  display: flex;
  align-items: center;
  gap: 0.5rem;
  transition: var(--transition);
}

.filter-btn:hover {
  background: var(--gray-light);
}

.flight-cards {
  display: flex;
  flex-direction: column;
  gap: 1rem;
}

.flight-card {
  background: white;
  border-radius: 1rem;
  padding: 1.5rem;
  box-shadow: var(--shadow-sm);
  display: flex;
  transition: var(--transition);
  cursor: pointer;
}

.flight-card:hover {
  transform: translateY(-3px);
  box-shadow: var(--shadow-md);
}

.flight-time {
  flex: 1;
  display: flex;
  flex-direction: column;
  align-items: center;
  gap: 0.5rem;
}

.flight-time span:first-child {
  font-size: 1.25rem;
  font-weight: 600;
}

.flight-time span:last-child {
  font-size: 0.875rem;
  color: var(--gray);
}

.flight-duration {
  flex: 2;
  display: flex;
  align-items: center;
  padding: 0 1rem;
  position: relative;
}

.flight-duration::before {
  content: "";
  position: absolute;
  left: 0;
  right: 0;
  height: 1px;
  background: var(--gray-light);
  top: 50%;
}

.flight-duration span {
  background: white;
  padding: 0 1rem;
  position: relative;
  z-index: 1;
  font-size: 0.875rem;
  color: var(--gray);
}

.flight-airline {
  flex: 1;
  display: flex;
  align-items: center;
  gap: 0.5rem;
}

.airline-logo {
  width: 32px;
  height: 32px;
  border-radius: 50%;
  background: var(--gray-light);
  display: flex;
  align-items: center;
  justify-content: center;
}

.flight-price {
  flex: 1;
  display: flex;
  flex-direction: column;
  align-items: flex-end;
}

.flight-price span:first-child {
  font-size: 1.25rem;
  font-weight: 700;
  color: var(--primary);
}

.flight-price span:last-child {
  font-size: 0.875rem;
  color: var(--gray);
}

/* Modal Styles */
.modal {
  display: none;
  position: fixed;
  top: 0;
  left: 0;
  width: 100%;
  height: 100%;
  background: rgba(0, 0, 0, 0.5);
  z-index: 1001;
  overflow-y: auto;
}

.modal-content {
  background: white;
  margin: 2rem auto;
  max-width: 800px;
  width: 90%;
  border-radius: 1rem;
  overflow: hidden;
  box-shadow: var(--shadow-lg);
  animation: modalFadeIn 0.3s ease;
}

@keyframes modalFadeIn {
  from {
    opacity: 0;
    transform: translateY(-20px);
  }
  to {
    opacity: 1;
    transform: translateY(0);
  }
}

.close-modal {
  position: absolute;
  top: 1rem;
  right: 1rem;
  font-size: 1.5rem;
  cursor: pointer;
  color: var(--gray);
  transition: var(--transition);
}

.close-modal:hover {
  color: var(--dark);
}

.booking-steps {
  display: flex;
  justify-content: space-between;
  padding: 1.5rem;
  background: var(--gray-light);
  position: relative;
}

.booking-steps::before {
  content: "";
  position: absolute;
  left: 1.5rem;
  right: 1.5rem;
  height: 2px;
  background: var(--gray);
  top: 50%;
  transform: translateY(-50%);
  z-index: 0;
}

.step {
  display: flex;
  flex-direction: column;
  align-items: center;
  gap: 0.5rem;
  z-index: 1;
}

.step span {
  width: 40px;
  height: 40px;
  border-radius: 50%;
  background: white;
  border: 2px solid var(--gray);
  display: flex;
  align-items: center;
  justify-content: center;
  font-weight: 600;
  color: var(--gray);
  transition: var(--transition);
}

.step p {
  font-size: 0.875rem;
  color: var(--gray);
  transition: var(--transition);
}

.step.active span {
  border-color: var(--primary);
  color: var(--primary);
}

.step.active p {
  color: var(--dark);
  font-weight: 500;
}

.booking-content {
  padding: 2rem;
}

/* Responsive Styles */
@media (max-width: 768px) {
  .nav-links {
    display: none;
    position: absolute;
    top: 100%;
    left: 0;
    width: 100%;
    background: white;
    flex-direction: column;
    gap: 0;
    box-shadow: var(--shadow-md);
  }

  .nav-links.active {
    display: flex;
  }

  .nav-links a {
    padding: 1rem 2rem;
    border-bottom: 1px solid var(--gray-light);
  }

  .nav-links a.active::after {
    display: none;
  }

  .user-dropdown {
    width: 100%;
  }

  .dropdown-content {
    position: static;
    width: 100%;
    box-shadow: none;
    border-radius: 0;
  }

  .hamburger {
    display: block;
  }

  .hero h1 {
    font-size: 2rem;
  }

  .search-form {
    grid-template-columns: 1fr;
  }

  .swap-btn {
    margin: 0 auto 1.5rem;
  }

  .recommendation-cards {
    grid-template-columns: 1fr;
  }

  .flight-card {
    flex-direction: column;
    gap: 1.5rem;
  }

  .flight-time,
  .flight-airline,
  .flight-price {
    align-items: flex-start;
  }

  .flight-duration {
    padding: 1rem 0;
  }

  .booking-steps {
    flex-direction: column;
    gap: 1.5rem;
    align-items: flex-start;
  }

  .booking-steps::before {
    display: none;
  }

  .step {
    flex-direction: row;
    gap: 1rem;
  }
}
```

**JavaScript (main.js)**

```javascript
// DOM Elements
const nav = document.querySelector('.glass-nav');
const hamburger = document.querySelector('.hamburger');
const navLinks = document.querySelector('.nav-links');
const originInput = document.getElementById('origin');
const destinationInput = document.getElementById('destination');
const originSuggestions = document.getElementById('origin-suggestions');
const destinationSuggestions = document.getElementById('destination-suggestions');
const swapBtn = document.querySelector('.swap-btn');
const travelersSelect = document.querySelector('.travelers-select');
const travelersDropdown = document.querySelector('.travelers-dropdown');
const searchBtn = document.querySelector('.search-btn');
const flightResults = document.getElementById('flight-results');
const flightCards = document.getElementById('flight-cards');
const sortBy = document.getElementById('sort-by');
const bookingModal = document.getElementById('booking-modal');
const closeModal = document.querySelector('.close-modal');
const bookingSteps = document.querySelectorAll('.step');
const bookingContent = document.querySelector('.booking-content');

// Sample Data
const airports = [
    { code: 'JFK', name: 'John F. Kennedy International Airport', city: 'New York' },
    { code: 'LAX', name: 'Los Angeles International Airport', city: 'Los Angeles' },
    { code: 'ORD', name: "O'Hare International Airport", city: 'Chicago' },
    { code: 'DFW', name: 'Dallas/Fort Worth International Airport', city: 'Dallas' },
    { code: 'DEN', name: 'Denver International Airport', city: 'Denver' },
    { code: 'SFO', name: 'San Francisco International Airport', city: 'San Francisco' },
    { code: 'SEA', name: 'Seattle-Tacoma International Airport', city: 'Seattle' },
    { code: 'MIA', name: 'Miami International Airport', city: 'Miami' },
    { code: 'ATL', name: 'Hartsfield-Jackson Atlanta International Airport', city: 'Atlanta' },
    { code: 'BOS', name: 'Logan International Airport', city: 'Boston' }
];

const flights = [
    {
        id: 'FL001',
        airline: 'Delta Airlines',
        airlineCode: 'DL',
        departure: { time: '08:00', airport: 'JFK' },
        arrival: { time: '11:30', airport: 'LAX' },
        duration: '6h 30m',
        price: 299,
        seats: 120,
        stops: 0,
        departureDate: '2023-06-15',
        arrivalDate: '2023-06-15'
    },
    {
        id: 'FL002',
        airline: 'American Airlines',
        airlineCode: 'AA',
        departure: { time: '10:15', airport: 'JFK' },
        arrival: { time: '13:45', airport: 'LAX' },
        duration: '6h 30m',
        price: 279,
        seats: 85,
        stops: 0,
        departureDate: '2023-06-15',
        arrivalDate: '2023-06-15'
    },
    {
        id: 'FL003',
        airline: 'United Airlines',
        airlineCode: 'UA',
        departure: { time: '12:30', airport: 'JFK' },
        arrival: { time: '18:15', airport: 'LAX' },
        duration: '8h 45m',
        price: 249,
        seats: 150,
        stops: 1,
        departureDate: '2023-06-15',
        arrivalDate: '2023-06-15'
    },
    {
        id: 'FL004',
        airline: 'JetBlue',
        airlineCode: 'B6',
        departure: { time: '15:45', airport: 'JFK' },
        arrival: { time: '19:15', airport: 'LAX' },
        duration: '6h 30m',
        price: 319,
        seats: 95,
        stops: 0,
        departureDate: '2023-06-15',
        arrivalDate: '2023-06-15'
    },
    {
        id: 'FL005',
        airline: 'Alaska Airlines',
        airlineCode: 'AS',
        departure: { time: '18:00', airport: 'JFK' },
        arrival: { time: '22:30', airport: 'LAX' },
        duration: '7h 30m',
        price: 269,
        seats: 110,
        stops: 0,
        departureDate: '2023-06-15',
        arrivalDate: '2023-06-15'
    }
];

const recommendations = [
    {
        id: 'REC001',
        destination: 'Paris, France',
        image: 'paris.jpg',
        description: 'Romantic getaway to the city of love',
        price: 599,
        duration: '7 days'
    },
    {
        id: 'REC002',
        destination: 'Tokyo, Japan',
        image: 'tokyo.jpg',
        description: 'Experience the vibrant culture of Japan',
        price: 899,
        duration: '10 days'
    },
    {
        id: 'REC003',
        destination: 'Cancun, Mexico',
        image: 'cancun.jpg',
        description: 'Relax on beautiful Caribbean beaches',
        price: 449,
        duration: '5 days'
    },
    {
        id: 'REC004',
        destination: 'Rome, Italy',
        image: 'rome.jpg',
        description: 'Explore ancient history and delicious cuisine',
        price: 699,
        duration: '8 days'
    }
];

// Event Listeners
document.addEventListener('DOMContentLoaded', () => {
    loadRecommendations();

    // Set minimum date for departure to today
    const today = new Date().toISOString().split('T')[0];
    document.getElementById('departure-date').min = today;

    // Set return date to 7 days after departure by default
    document.getElementById('departure-date').addEventListener('change', (e) => {
        const returnDate = document.getElementById('return-date');
        if (e.target.value) {
            const departureDate = new Date(e.target.value);
            departureDate.setDate(departureDate.getDate() + 7);
            const nextWeek = departureDate.toISOString().split('T')[0];
            returnDate.min = e.target.value;
            returnDate.value = nextWeek;
        }
    });
});

window.addEventListener('scroll', () => {
    if (window.scrollY > 50) {
        nav.classList.add('scrolled');
    } else {
        nav.classList.remove('scrolled');
    }
});

hamburger.addEventListener('click', () => {
    navLinks.classList.toggle('active');
});

originInput.addEventListener('input', (e) => {
    showAirportSuggestions(e.target.value, originSuggestions);
});

destinationInput.addEventListener('input', (e) => {
    showAirportSuggestions(e.target.value, destinationSuggestions);
});

originSuggestions.addEventListener('click', (e) => {
    if (e.target.tagName === 'DIV') {
        const airportCode = e.target.getAttribute('data-code');
        const airportName = e.target.getAttribute('data-name');
        originInput.value = `${airportName} (${airportCode})`;
        originSuggestions.style.display = 'none';
    }
});

destinationSuggestions.addEventListener('click', (e) => {
    if (e.target.tagName === 'DIV') {
        const airportCode = e.target.getAttribute('data-code');
        const airportName = e.target.getAttribute('data-name');
        destinationInput.value = `${airportName} (${airportCode})`;
        destinationSuggestions.style.display = 'none';
    }
});

swapBtn.addEventListener('click', () => {
    const temp = originInput.value;
    originInput.value = destinationInput.value;
    destinationInput.value = temp;
});

travelersSelect.addEventListener('click', () => {
    travelersDropdown.style.display = travelersDropdown.style.display === 'block' ? 'none' : 'block';
});

document.addEventListener('click', (e) => {
    if (!travelersSelect.contains(e.target) {
        travelersDropdown.style.display = 'none';
    }

    if (e.target !== originInput && e.target !== destinationInput) {
        originSuggestions.style.display = 'none';
        destinationSuggestions.style.display = 'none';
    }
});

searchBtn.addEventListener('click', () => {
    showFlightResults();
});

sortBy.addEventListener('change', () => {
    sortFlights();
});

closeModal.addEventListener('click', () => {
    bookingModal.style.display = 'none';
});

window.addEventListener('click', (e) => {
    if (e.target === bookingModal) {
        bookingModal.style.display = 'none';
    }
});

bookingSteps.forEach(step => {
    step.addEventListener('click', () => {
        const stepNumber = step.getAttribute('data-step');
        showBookingStep(stepNumber);
    });
});

// Functions
function showAirportSuggestions(query, container) {
    if (!query) {
        container.style.display = 'none';
        return;
    }

    const filtered = airports.filter(airport =>
        airport.code.toLowerCase().includes(query.toLowerCase()) ||
        airport.name.toLowerCase().includes(query.toLowerCase()) ||
        airport.city.toLowerCase().includes(query.toLowerCase())
    );

    container.innerHTML = '';

    if (filtered.length === 0) {
        container.style.display = 'none';
        return;
    }

    filtered.forEach(airport => {
        const div = document.createElement('div');
        div.textContent = `${airport.city} (${airport.code}) - ${airport.name}`;
        div.setAttribute('data-code', airport.code);
        div.setAttribute('data-name', `${airport.city} (${airport.code})`);
        container.appendChild(div);
    });

    container.style.display = 'block';
}

function loadRecommendations() {
    const container = document.querySelector('.recommendation-cards');
    container.innerHTML = '';

    recommendations.forEach(rec => {
        const card = document.createElement('div');
        card.className = 'recommendation-card';
        card.innerHTML = `
            <div class="card-image">
                <img src="images/${rec.image}" alt="${rec.destination}">
            </div>
            <div class="card-content">
                <h3>${rec.destination}</h3>
                <p>${rec.description}</p>
                <div class="card-price">$${rec.price}</div>
            </div>
        `;
        container.appendChild(card);
    });
}

function showFlightResults() {
    flightResults.style.display = 'block';
    flightCards.innerHTML = '';

    flights.forEach(flight => {
        const card = document.createElement('div');
        card.className = 'flight-card';
        card.setAttribute('data-id', flight.id);
        card.innerHTML = `
            <div class="flight-time">
                <span>${flight.departure.time}</span>
                <span>${flight.departure.airport}</span>
            </div>
            <div class="flight-duration">
                <span>${flight.duration}</span>
            </div>
            <div class="flight-time">
                <span>${flight.arrival.time}</span>
                <span>${flight.arrival.airport}</span>
            </div>
            <div class="flight-airline">
                <div class="airline-logo">
                    ${flight.airlineCode}
                </div>
                <span>${flight.airline}</span>
            </div>
            <div class="flight-price">
                <span>$${flight.price}</span>
                <span>Round trip</span>
            </div>
        `;
        flightCards.appendChild(card);

        card.addEventListener('click', () => {
            openBookingModal(flight);
        });
    });

    // Scroll to results
    flightResults.scrollIntoView({ behavior: 'smooth' });
}

function sortFlights() {
    const value = sortBy.value;
    let sortedFlights = [...flights];

    switch (value) {
        case 'price-asc':
            sortedFlights.sort((a, b) => a.price - b.price);
            break;
        case 'price-desc':
            sortedFlights.sort((a, b) => b.price - a.price);
            break;
        case 'duration-asc':
            sortedFlights.sort((a, b) => {
                const aDuration = convertDurationToMinutes(a.duration);
                const bDuration = convertDurationToMinutes(b.duration);
                return aDuration - bDuration;
            });
            break;
        case 'departure-asc':
            sortedFlights.sort((a, b) => a.departure.time.localeCompare(b.departure.time));
            break;
    }

    flightCards.innerHTML = '';
    sortedFlights.forEach(flight => {
        const card = document.createElement('div');
        card.className = 'flight-card';
        card.setAttribute('data-id', flight.id);
        card.innerHTML = `
            <div class="flight-time">
                <span>${flight.departure.time}</span>
                <span>${flight.departure.airport}</span>
            </div>
            <div class="flight-duration">
                <span>${flight.duration}</span>
            </div>
            <div class="flight-time">
                <span>${flight.arrival.time}</span>
                <span>${flight.arrival.airport}</span>
            </div>
            <div class="flight-airline">
                <div class="airline-logo">
                    ${flight.airlineCode}
                </div>
                <span>${flight.airline}</span>
            </div>
            <div class="flight-price">
                <span>$${flight.price}</span>
                <span>Round trip</span>
            </div>
        `;
        flightCards.appendChild(card);

        card.addEventListener('click', () => {
            openBookingModal(flight);
        });
    });
}

function convertDurationToMinutes(duration) {
    const parts = duration.split(' ');
    let total = 0;

    parts.forEach(part => {
        if (part.includes('h')) {
            total += parseInt(part) * 60;
        } else if (part.includes('m')) {
            total += parseInt(part);
        }
    });

    return total;
}

function openBookingModal(flight) {
    bookingModal.style.display = 'block';
    showBookingStep('1');

    // Set flight details in step 1
    const step1Content = `
        <div class="flight-details">
            <h3>Flight Details</h3>
            <div class="flight-summary">
                <div class="flight-info">
                    <div class="flight-segment">
                        <div class="segment-time">
                            <span>${flight.departure.time}</span>
                            <span>${flight.departure.airport}</span>
                        </div>
                        <div class="segment-duration">
                            <span>${flight.duration}</span>
                        </div>
                        <div class="segment-time">
                            <span>${flight.arrival.time}</span>
                            <span>${flight.arrival.airport}</span>
                        </div>
                    </div>
                    <div class="flight-airline">
                        <div class="airline-logo">
                            ${flight.airlineCode}
                        </div>
                        <span>${flight.airline}</span>
                    </div>
                </div>
                <div class="flight-price">
                    <span>Total Price</span>
                    <span class="price">$${flight.price}</span>
                </div>
            </div>
            <button class="next-btn">Continue to Passenger Info</button>
        </div>
    `;

    bookingContent.innerHTML = step1Content;

    // Add event listener for next button
    document.querySelector('.next-btn')?.addEventListener('click', () => {
        showBookingStep('2');
    });
}

function showBookingStep(stepNumber) {
    // Update active step
    bookingSteps.forEach(step => {
        if (step.getAttribute('data-step') === stepNumber) {
            step.classList.add('active');
        } else {
            step.classList.remove('active');
        }
    });

    // Show appropriate content
    switch (stepNumber) {
        case '1':
            // Already set in openBookingModal
            break;
        case '2':
            bookingContent.innerHTML = `
                <div class="passenger-info">
                    <h3>Passenger Information</h3>
                    <form id="passenger-form">
                        <div class="form-group">
                            <label for="first-name">First Name</label>
                            <input type="text" id="first-name" required>
                        </div>
                        <div class="form-group">
                            <label for="last-name">Last Name</label>
                            <input type="text" id="last-name" required>
                        </div>
                        <div class="form-group">
                            <label for="email">Email</label>
                            <input type="email" id="email" required>
                        </div>
                        <div class="form-group">
                            <label for="phone">Phone Number</label>
                            <input type="tel" id="phone" required>
                        </div>
                        <div class="form-group">
                            <label for="passport">Passport Number</label>
                            <input type="text" id="passport" required>
                        </div>
                        <div class="form-actions">
                            <button type="button" class="back-btn">Back</button>
                            <button type="button" class="next-btn">Continue to Seat Selection</button>
                        </div>
                    </form>
                </div>
            `;

            document.querySelector('.back-btn')?.addEventListener('click', () => {
                showBookingStep('1');
            });

            document.querySelector('.next-btn')?.addEventListener('click', () => {
                showBookingStep('3');
            });
            break;
        case '3':
            bookingContent.innerHTML = `
                <div class="seat-selection">
                    <h3>Seat Selection</h3>
                    <div class="seat-map">
                        <div class="airplane-cabin">
                            <div class="cabin-front">Front</div>
                            <div class="seat-rows">
                                ${generateSeatMap()}
                            </div>
                        </div>
                    </div>
                    <div class="seat-legend">
                        <div class="legend-item">
                            <div class="seat available"></div>
                            <span>Available</span>
                        </div>
                        <div class="legend-item">
                            <div class="seat selected"></div>
                            <span>Selected</span>
                        </div>
                        <div class="legend-item">
                            <div class="seat occupied"></div>
                            <span>Occupied</span>
                        </div>
                    </div>
                    <div class="form-actions">
                        <button type="button" class="back-btn">Back</button>
                        <button type="button" class="next-btn">Continue to Payment</button>
                    </div>
                </div>
            `;

            // Add seat selection functionality
            document.querySelectorAll('.seat.available').forEach(seat => {
                seat.addEventListener('click', function() {
                    this.classList.toggle('selected');
                });
            });

            document.querySelector('.back-btn')?.addEventListener('click', () => {
                showBookingStep('2');
            });

            document.querySelector('.next-btn')?.addEventListener('click', () => {
                showBookingStep('4');
            });
            break;
        case '4':
            bookingContent.innerHTML = `
                <div class="payment">
                    <h3>Payment Information</h3>
                    <form id="payment-form">
                        <div class="form-group">
                            <label for="card-number">Card Number</label>
                            <input type="text" id="card-number" placeholder="1234 5678 9012 3456" required>
                        </div>
                        <div class="form-row">
                            <div class="form-group">
                                <label for="expiry">Expiry Date</label>
                                <input type="text" id="expiry" placeholder="MM/YY" required>
                            </div>
                            <div class="form-group">
                                <label for="cvv">CVV</label>
                                <input type="text" id="cvv" placeholder="123" required>
                            </div>
                        </div>
                        <div class="form-group">
                            <label for="card-name">Name on Card</label>
                            <input type="text" id="card-name" required>
                        </div>
                        <div class="form-actions">
                            <button type="button" class="back-btn">Back</button>
                            <button type="submit" class="submit-btn">Confirm Payment</button>
                        </div>
                    </form>
                </div>
            `;

            document.querySelector('.back-btn')?.addEventListener('click', () => {
                showBookingStep('3');
            });

            document.getElementById('payment-form')?.addEventListener('submit', (e) => {
                e.preventDefault();
                showBookingStep('5');
            });
            break;
        case '5':
            bookingContent.innerHTML = `
                <div class="confirmation">
                    <div class="confirmation-icon">
                        <i class="fas fa-check-circle"></i>
                    </div>
                    <h3>Booking Confirmed!</h3>
                    <p>Your flight has been successfully booked. A confirmation email has been sent to your registered email address.</p>
                    <div class="booking-reference">
                        <span>Booking Reference:</span>
                        <strong>SKY${Math.floor(100000 + Math.random() * 900000)}</strong>
                    </div>
                    <button class="done-btn">Return to Home</button>
                </div>
            `;

            document.querySelector('.done-btn')?.addEventListener('click', () => {
                bookingModal.style.display = 'none';
                window.scrollTo({ top: 0, behavior: 'smooth' });
            });
            break;
    }
}

function generateSeatMap() {
    let html = '';
    const rows = 20;
    const seatsPerRow = 6;
    const occupiedSeats = new Set();

    // Randomly occupy some seats
    for (let i = 0; i < 30; i++) {
        const row = Math.floor(Math.random() * rows) + 1;
        const seat = String.fromCharCode(65 + Math.floor(Math.random() * seatsPerRow));
        occupiedSeats.add(`${row}${seat}`);
    }

    for (let row = 1; row <= rows; row++) {
        html += `<div class="seat-row">`;
        html += `<div class="row-number">${row}</div>`;

        for (let seatNum = 0; seatNum < seatsPerRow; seatNum++) {
            const seatLetter = String.fromCharCode(65 + seatNum);
            const seatId = `${row}${seatLetter}`;
            const isOccupied = occupiedSeats.has(seatId);
            const seatClass = isOccupied ? 'occupied' : 'available';

            // Add aisle gap
            if (seatNum === 3) {
                html += `<div class="aisle-gap"></div>`;
            }

            html += `<div class="seat ${seatClass}" data-seat="${seatId}">${seatLetter}</div>`;
        }

        html += `</div>`;
    }

    return html;
}
```

## Backend Database Structure (MySQL)

**Database Schema (airline_management.sql)**

```sql
-- Create database
CREATE DATABASE IF NOT EXISTS airline_management;
USE airline_management;

-- Users table
CREATE TABLE users (
    user_id INT AUTO_INCREMENT PRIMARY KEY,
    username VARCHAR(50) NOT NULL UNIQUE,
    password_hash VARCHAR(255) NOT NULL,
    email VARCHAR(100) NOT NULL UNIQUE,
    first_name VARCHAR(50) NOT NULL,
    last_name VARCHAR(50) NOT NULL,
    phone VARCHAR(20),
    passport_number VARCHAR(50),
    user_type ENUM('customer', 'admin') DEFAULT 'customer',
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
);

-- Airports table
CREATE TABLE airports (
    airport_code VARCHAR(3) PRIMARY KEY,
    airport_name VARCHAR(100) NOT NULL,
    city VARCHAR(50) NOT NULL,
    country VARCHAR(50) NOT NULL,
    timezone VARCHAR(50) NOT NULL
);

-- Airlines table
CREATE TABLE airlines (
    airline_code VARCHAR(2) PRIMARY KEY,
    airline_name VARCHAR(50) NOT NULL,
    logo_url VARCHAR(255)
);

-- Aircraft table
CREATE TABLE aircraft (
    aircraft_id INT AUTO_INCREMENT PRIMARY KEY,
    model VARCHAR(50) NOT NULL,
    manufacturer VARCHAR(50) NOT NULL,
    capacity INT NOT NULL,
    seat_map JSON NOT NULL
);

-- Flights table
CREATE TABLE flights (
    flight_id VARCHAR(10) PRIMARY KEY,
    airline_code VARCHAR(2) NOT NULL,
    aircraft_id INT NOT NULL,
    departure_airport VARCHAR(3) NOT NULL,
    arrival_airport VARCHAR(3) NOT NULL,
    departure_time DATETIME NOT NULL,
    arrival_time DATETIME NOT NULL,
    duration_minutes INT NOT NULL,
    base_price DECIMAL(10, 2) NOT NULL,
    status ENUM('scheduled', 'delayed', 'cancelled', 'completed') DEFAULT 'scheduled',
    FOREIGN KEY (airline_code) REFERENCES airlines(airline_code),
    FOREIGN KEY (aircraft_id) REFERENCES aircraft(aircraft_id),
    FOREIGN KEY (departure_airport) REFERENCES airports(airport_code),
    FOREIGN KEY (arrival_airport) REFERENCES airports(airport_code)
);

-- Flight seats table (for tracking availability)
CREATE TABLE flight_seats (
    seat_id INT AUTO_INCREMENT PRIMARY KEY,
    flight_id VARCHAR(10) NOT NULL,
    seat_number VARCHAR(5) NOT NULL,
    class ENUM('economy', 'premium_economy', 'business', 'first') NOT NULL,
    is_available BOOLEAN DEFAULT TRUE,
    price_modifier DECIMAL(5, 2) DEFAULT 1.0,
    FOREIGN KEY (flight_id) REFERENCES flights(flight_id),
    UNIQUE KEY (flight_id, seat_number)
);

-- Bookings table
CREATE TABLE bookings (
    booking_id VARCHAR(12) PRIMARY KEY,
    user_id INT NOT NULL,
    flight_id VARCHAR(10) NOT NULL,
    booking_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    total_price DECIMAL(10, 2) NOT NULL,
    status ENUM('pending', 'confirmed', 'cancelled', 'completed') DEFAULT 'pending',
    payment_status ENUM('unpaid', 'paid', 'refunded') DEFAULT 'unpaid',
    FOREIGN KEY (user_id) REFERENCES users(user_id),
    FOREIGN KEY (flight_id) REFERENCES flights(flight_id)
);

-- Passengers table (for multiple passengers per booking)
CREATE TABLE passengers (
    passenger_id INT AUTO_INCREMENT PRIMARY KEY,
    booking_id VARCHAR(12) NOT NULL,
    first_name VARCHAR(50) NOT NULL,
    last_name VARCHAR(50) NOT NULL,
    passport_number VARCHAR(50),
    seat_number VARCHAR(5),
    meal_preference VARCHAR(50),
    special_requests TEXT,
    FOREIGN KEY (booking_id) REFERENCES bookings(booking_id)
);

-- Payments table
CREATE TABLE payments (
    payment_id INT AUTO_INCREMENT PRIMARY KEY,
    booking_id VARCHAR(12) NOT NULL,
    amount DECIMAL(10, 2) NOT NULL,
    payment_method ENUM('credit_card', 'debit_card', 'paypal', 'bank_transfer') NOT NULL,
    payment_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    transaction_id VARCHAR(100),
    status ENUM('pending', 'completed', 'failed', 'refunded') DEFAULT 'pending',
    FOREIGN KEY (booking_id) REFERENCES bookings(booking_id)
);

-- Sample data insertion
INSERT INTO airports (airport_code, airport_name, city, country, timezone) VALUES
('JFK', 'John F. Kennedy International Airport', 'New York', 'USA', 'America/New_York'),
('LAX', 'Los Angeles International Airport', 'Los Angeles', 'USA', 'America/Los_Angeles'),
('ORD', 'O''Hare International Airport', 'Chicago', 'USA', 'America/Chicago'),
('DFW', 'Dallas/Fort Worth International Airport', 'Dallas', 'USA', 'America/Chicago'),
('SFO', 'San Francisco International Airport', 'San Francisco', 'USA', 'America/Los_Angeles');

INSERT INTO airlines (airline_code, airline_name) VALUES
('DL', 'Delta Airlines'),
('AA', 'American Airlines'),
('UA', 'United Airlines'),
('B6', 'JetBlue'),
('AS', 'Alaska Airlines');

INSERT INTO aircraft (model, manufacturer, capacity, seat_map) VALUES
('Boeing 737-800', 'Boeing', 162, '{"rows": 27, "seats_per_row": 6, "business_rows": 4, "premium_rows": 8}'),
('Airbus A320', 'Airbus', 150, '{"rows": 25, "seats_per_row": 6, "business_rows": 3, "premium_rows": 7}'),
('Boeing 787-9', 'Boeing', 290, '{"rows": 42, "seats_per_row": 8, "business_rows": 8, "premium_rows": 12}');

INSERT INTO flights (flight_id, airline_code, aircraft_id, departure_airport, arrival_airport, departure_time, arrival_time, duration_minutes, base_price) VALUES
('DL123', 'DL', 1, 'JFK', 'LAX', '2023-06-15 08:00:00', '2023-06-15 11:30:00', 390, 299.00),
('AA456', 'AA', 2, 'JFK', 'LAX', '2023-06-15 10:15:00', '2023-06-15 13:45:00', 390, 279.00),
('UA789', 'UA', 3, 'JFK', 'LAX', '2023-06-15 12:30:00', '2023-06-15 18:15:00', 525, 249.00),
('B6101', 'B6', 1, 'JFK', 'LAX', '2023-06-15 15:45:00', '2023-06-15 19:15:00', 390, 319.00),
('AS202', 'AS', 2, 'JFK', 'LAX', '2023-06-15 18:00:00', '2023-06-15 22:30:00', 450, 269.00);

-- Insert sample seat data for one flight
INSERT INTO flight_seats (flight_id, seat_number, class, is_available, price_modifier)
SELECT 'DL123', CONCAT(rows.row_num, cols.col_letter),
       CASE
           WHEN rows.row_num <= 4 THEN 'business'
           WHEN rows.row_num <= 12 THEN 'premium_economy'
           ELSE 'economy'
       END,
       TRUE,
       CASE
           WHEN rows.row_num <= 4 THEN 2.5
           WHEN rows.row_num <= 12 THEN 1.5
           ELSE 1.0
       END
FROM (
    SELECT 1 AS row_num UNION SELECT 2 UNION SELECT 3 UNION SELECT 4 UNION
    SELECT 5 UNION SELECT 6 UNION SELECT 7 UNION SELECT 8 UNION
    SELECT 9 UNION SELECT 10 UNION SELECT 11 UNION SELECT 12 UNION
    SELECT 13 UNION SELECT 14 UNION SELECT 15 UNION SELECT 16 UNION
    SELECT 17 UNION SELECT 18 UNION SELECT 19 UNION SELECT 20 UNION
    SELECT 21 UNION SELECT 22 UNION SELECT 23 UNION SELECT 24 UNION
    SELECT 25 UNION SELECT 26 UNION SELECT 27
) AS rows
CROSS JOIN (
    SELECT 'A' AS col_letter UNION SELECT 'B' UNION SELECT 'C' UNION
    SELECT 'D' UNION SELECT 'E' UNION SELECT 'F'
) AS cols;

-- Sample admin user
INSERT INTO users (username, password_hash, email, first_name, last_name, phone, passport_number, user_type)
VALUES ('admin', '$2a$10$xJwL5v5zLt3X5Zq9UQd8Ue9W5v6vQ5VfXe5vY7w8x9y0z1A2B3C4D', 'admin@skyvoyage.com', 'Admin', 'User', '1234567890', NULL, 'admin');

-- Sample customer user
INSERT INTO users (username, password_hash, email, first_name, last_name, phone, passport_number, user_type)
VALUES ('johndoe', '$2a$10$xJwL5v5zLt3X5Zq9UQd8Ue9W5v6vQ5VfXe5vY7w8x9y0z1A2B3C4D', 'john.doe@example.com', 'John', 'Doe', '9876543210', 'P12345678', 'customer');
```

## Documentation

### 1. Software Requirements Specification (SRS)

**1.1 Introduction**
The SkyVoyage Airline Management System is a modern web application designed to provide customers with an intuitive interface for flight booking and administrators with powerful tools for flight management.

**1.2 Functional Requirements**

- User Registration & Authentication
- Flight Search & Booking
- Seat Selection
- Payment Processing
- Booking Management
- Flight Management (Admin)
- User Management (Admin)
- Reporting & Analytics (Admin)

**1.3 Non-Functional Requirements**

- Responsive design for all device sizes
- Fast loading times (<2s page load)
- Secure data handling (encrypted passwords, HTTPS)
- Intuitive UX with minimal clicks to complete tasks

### 2. UML Diagrams

**2.1 Class Diagram**

```
+----------------+       +----------------+       +----------------+
|     User       |       |    Flight      |       |   Booking      |
+----------------+       +----------------+       +----------------+
| - userId       |       | - flightId     |       | - bookingId    |
| - username     |       | - airlineCode  |       | - userId       |
| - passwordHash |       | - aircraftId   |       | - flightId     |
| - email        |       | - departure    |       | - bookingDate  |
| - firstName    |       | - arrival      |       | - totalPrice   |
| - lastName     |       | - departureTime|       | - status       |
| - phone        |       | - arrivalTime  |       +----------------+
| - passport     |       | - duration     |               /\
| - userType     |       | - basePrice    |               |
+----------------+       | - status       |               |
        /\               +----------------+               |
        |                       /\                       |
        |                       |                        |
+----------------+       +----------------+       +----------------+
|    Admin       |       |   Aircraft     |       |   Passenger    |
+----------------+       +----------------+       +----------------+
| (inherits from |       | - aircraftId   |       | - passengerId  |
| User)          |       | - model        |       | - bookingId    |
+----------------+       | - manufacturer |       | - firstName    |
                         | - capacity     |       | - lastName     |
                         | - seatMap      |       | - passport     |
                         +----------------+       | - seatNumber   |
                                                  +----------------+
```

**2.2 Use Case Diagram**

```
+----------------+       +-----------------------+
|     User       |       |       System          |
+----------------+       +-----------------------+
       |                         /\
       | Register                |
       | Login                   |
       | Search Flights          |
       | Book Flight            |
       | Select Seat            |
       | Make Payment           |
       | View Bookings          |
       |                         |
+----------------+               |
|    Admin       |               |
+----------------+               |
       |                         |
       | Manage Flights          |
       | Manage Users            |
       | View Reports            |
       |                         |
+----------------+               |
|     Guest      |               |
+----------------+               |
       |                         |
       | Browse Flights          |
       |                         |
+-------------------------------+
```

**2.3 ER Diagram**

```
+-------------+       +-------------+       +-------------+
|    USER     |       |   FLIGHT    |       |  BOOKING    |
+-------------+       +-------------+       +-------------+
| PK user_id  |------>| PK flight_id|<------| PK booking_|
| username    |       | FK airline_ |       | FK user_id  |
| password    |       | FK aircraft_|       | FK flight_id|
| email       |       | FK departur |       | booking_date|
| first_name  |       | FK arrival_ |       | total_price |
| last_name   |       | departure_t |       | status      |
| phone       |       | arrival_tim |       | payment_sta |
| passport_no |       | duration    |       +-------------+
| user_type   |       | base_price  |              /\
+-------------+       | status      |              |
                      +-------------+              |
                            /\                    |
                            |                     |
                      +-------------+      +-------------+
                      |  AIRCRAFT   |      | PASSENGER   |
                      +-------------+      +-------------+
                      | PK aircraft |      | PK passenge |
                      | model       |      | FK booking_ |
                      | manufactur  |      | first_name  |
                      | capacity    |      | last_name   |
                      | seat_map    |      | passport_no |
                      +-------------+      | seat_number |
                                           | meal_pref   |
                                           +-------------+
```

**2.4 Data Flow Diagram (Level 0)**

```
+-------------+       +-------------------+       +-------------+
|    User     |------>| Flight Search &   |------>|  Database   |
| (Customer)  |<------| Booking System    |<------|             |
+-------------+       +-------------------+       +-------------+
                           /\
                           ||
                           \/
+-------------+       +-------------------+       +-------------+
|    Admin    |------>| Management        |------>| Reporting   |
|             |<------| Dashboard         |<------| System      |
+-------------+       +-------------------+       +-------------+
```

**2.5 Sequence Diagram (Flight Booking)**

```
User                   System                  Database
 |                       |                       |
 |--Search Flights------->|                       |
 |                       |---Query Flights------->|
 |                       |<---Return Results-----|
 |<--Display Results-----|                       |
 |                       |                       |
 |--Select Flight------->|                       |
 |                       |---Check Availability->|
 |                       |<---Return Status-----|
 |<--Show Booking Form---|                       |
 |                       |                       |
 |--Submit Booking------>|                       |
 |                       |---Create Booking----->|
 |                       |<---Confirm Booking---|
 |<--Show Confirmation---|                       |
 |                       |                       |
 |--Make Payment-------->|                       |
 |                       |---Process Payment--->|
 |                       |<---Payment Result---|
 |<--Payment Confirmation|                       |
```

## Setup Instructions

1. **Frontend Setup**

   - Create project folder structure:
     ```
     /skyvoyage
       /css
         main.css
       /js
         main.js
       /images
         hero-bg.jpg
         paris.jpg
         tokyo.jpg
         cancun.jpg
         rome.jpg
         user-avatar.png
       index.html
     ```

2. **Database Setup**

   - Install MySQL if not already installed
   - Create database using the provided SQL script:
     ```bash
     mysql -u root -p < airline_management.sql
     ```

3. **Running the Application**
   - For frontend: Open index.html in a web browser
   - For backend: You would typically set up a Node.js/Express server to connect to the MySQL database (not included in this frontend implementation)

## Key Features Implemented

1. **Modern UI/UX**

   - Glassmorphism navigation bar
   - Animated hero section with flight search
   - Responsive design for all screen sizes
   - Smooth transitions and hover effects

2. **Interactive Flight Search**

   - Real-time airport suggestions
   - Date picker with validation
   - Traveler selector with counter
   - Swap origin/destination functionality

3. **Booking Flow**

   - Multi-step booking process
   - Flight details confirmation
   - Passenger information form
   - Interactive seat map
   - Payment processing

4. **Personalization**

   - User profile dropdown
   - Personalized flight recommendations
   - Welcome message for logged-in users

5. **Admin Features**
   - Flight management interface
   - User management
   - Reporting dashboard
     This implementation provides a solid foundation that can be extended with backend functionality using Node.js, PHP, or other server-side technologies to connect to the MySQL database.
