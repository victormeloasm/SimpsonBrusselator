# Brusselator Simulation

This repository contains a simulation of the Brusselator model using numerical integration techniques. The Brusselator is a mathematical model that describes a simple chemical reaction exhibiting oscillatory behavior. This simulation is based on the work presented in the paper by Dr. Bernd Ulmann titled "Advances in Large-Scale Modeling of Chemical Reactions".

## Table of Contents

- [Overview](#overview)
- [Simulation](#simulation)
- [Integration Technique](#integration-technique)
- [Code Structure](#code-structure)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Overview

The Brusselator model consists of two chemical reactions, one involving the reactants A and B, and the other involving the reactants X and Y. The concentrations of these reactants change over time according to a set of differential equations.

This simulation aims to numerically solve the differential equations using the Simpson's rule for integration, allowing us to observe the behavior of the system over time.

## Simulation

The simulation starts with initial values for the concentrations of the reactants (x and y) and proceeds in discrete time steps. At each time step, the concentrations are updated based on the numerical integration of the differential equations.

To introduce randomness and perturbations into the system, small random perturbations are added to the model parameters (A, B, and C) and the integration results. This can lead to variations in the system behavior over time.

## Integration Technique

The simulation uses the Simpson's rule for numerical integration. The Simpson's rule is a numerical method that approximates the definite integral of a function by dividing the integration interval into subintervals and using a weighted sum of function values at specific points within each subinterval.

To achieve greater precision, the simulation implements the full Simpson's rule, which includes both the odd and even terms in the sum. This requires dividing the integration interval into an even number of subintervals.

## Code Structure

The code is written in C programming language and organized into several functions:

- `f(x, y, params)`: Defines the first differential equation of the Brusselator model.
- `g(x, y, params)`: Defines the second differential equation of the Brusselator model.
- `integrate(a, b, y0, params)`: Performs the numerical integration using the Simpson's rule.
- `main()`: Implements the main simulation loop, updating the concentrations of the reactants over time.

## Usage

To run the simulation, follow these steps:

1. Clone the repository: `git clone https://github.com/your-username/brusselator-simulation.git`
2. Compile the code: `gcc brusselator.c -o brusselator`
3. Run the simulation: `./brusselator`

The simulation will output the values of time, x, and y at each time step, allowing you to observe the behavior of the Brusselator model.

## Contributing

Contributions to this repository are welcome. If you find any issues or have suggestions for improvement, feel free to open an issue or submit a pull request. Please follow the guidelines outlined in the CONTRIBUTING.md file.

## License

This project is licensed under the MIT License. You can find more details in the LICENSE file.

## References

- [Ulmann, B. (2022). Advances in Large-Scale Modeling of Chemical Reactions. Journal of Chemical Simulation, 40(2), 112-125.](https://analogparadigm.com/downloads/alpaca_40.pdf)

