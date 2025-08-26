# Fluid Simulator

A real-time 2D fluid simulation application built with Qt and OpenGL, implementing Smoothed Particle Hydrodynamics (SPH) for realistic fluid behavior.

![Fluid Simulator Logo](Images/Logo.png)

## 🌊 Overview

This application simulates fluid dynamics using the SPH (Smoothed Particle Hydrodynamics) method, allowing users to interact with particles in real-time. The simulator provides various tools for creating, manipulating, and analyzing fluid behavior with different material properties.

**Based on**: This project builds upon the SPH implementation from [mueller-sph](https://github.com/lucas-schuermann/mueller-sph.git) by Lucas Schuermann, extending it with a complete Qt-based GUI, real-time interaction tools, and advanced visualization features.

## ✨ Features

### Core Simulation
- **Real-time SPH Physics**: Accurate fluid simulation using density, pressure, and viscosity calculations
- **Gravity Control**: Adjustable gravity in X and Y directions
- **Boundary Collision**: Particles bounce off window boundaries with configurable damping

### Interactive Tools
- **Particle Creation**: Left-click to add particles, right-click to create particle streams
- **Particle Selection**: Click to select and monitor individual particles
- **Launch Tool**: Drag to set velocity and direction for particle launching
- **Concentric Force**: Apply radial forces at mouse position
- **Delete Tool**: Remove particles by clicking or dragging

### Visualization & Monitoring
- **Real-time Rendering**: OpenGL-based particle visualization with smooth circular points
- **Particle Monitor**: Real-time display of selected particle properties:
  - Position and velocity vectors
  - Force components (gravity, pressure, viscosity)
  - Energy calculations (kinetic, potential, mechanical)
- **Energy Chart**: Graphical representation of particle energy states
- **FPS Counter**: Performance monitoring

### Simulation Controls
- **Play/Pause**: Start and stop the simulation
- **Time Navigation**: Step forward/backward through simulation history
- **Large Steps**: Jump 20 frames forward/backward
- **Reset**: Clear all particles and restart

## 🛠️ Technical Details

### Physics Implementation
- **SPH Kernels**: Uses Poly6, Spiky, and Viscosity kernels for different calculations
- **Parallel Processing**: OpenMP parallelization for performance optimization
- **Numerical Integration**: Forward Euler integration for particle movement
- **Force Calculations**: 
  - Pressure forces using equation of state
  - Viscosity forces for fluid coherence
  - Gravitational forces
  - External forces (concentric, launch)

### Architecture
- **Qt Framework**: Cross-platform GUI with OpenGL integration
- **Eigen Library**: High-performance linear algebra operations
- **Modular Design**: Separated physics, rendering, and UI components
- **Global State Management**: Centralized variable management system

## 📋 Requirements

### System Requirements
- **OS**: Linux (primary) / Windows (supported)
- **Graphics**: OpenGL-compatible graphics card
- **Memory**: Sufficient RAM for particle simulation (scales with particle count)

### Dependencies
- **Qt 5/6**: Core, GUI, Widgets, OpenGL
- **Eigen 3**: Linear algebra library
- **OpenMP**: Parallel processing support
- **OpenGL**: Graphics rendering

## 🚀 Installation

### Linux (Primary Platform)
```bash
# Install dependencies (Ubuntu/Debian)
sudo apt update
sudo apt install qt5-default libeigen3-dev libgomp1

# Clone the repository
git clone https://github.com/MateoMor/Fluid-Simulator.git
cd Fluid-Simulator

# Build the project
qmake fluid_simulator.pro
make

# Run the application
./fluid_simulator
```

### Windows
```bash
# Ensure Qt and required libraries are installed
# Open the project in Qt Creator or use command line:

qmake fluid_simulator.pro
nmake  # or mingw32-make

# Run the executable
fluid_simulator.exe
```

## 🎮 Usage Guide

### Basic Controls
1. **Start Simulation**: Click the play button or press the start action
2. **Add Particles**: 
   - Right-click to add single particles
   - Hold right-click and drag to create particle streams
3. **Select Particles**: Left-click on a particle to select and monitor it
4. **Use Tools**: Select tools from the toolbar:
   - **Launch Tool**: Drag to set particle velocity and direction
   - **Concentric Force**: Apply radial forces at mouse position
   - **Delete Tool**: Remove particles by clicking

### Simulation Parameters
- **Gravity**: Adjust X and Y gravity components using the spin boxes
- **Fluid Type**: Choose from the dropdown menu (Default, Water, Oil)
- **Particle Properties**: Each fluid type has different:
  - Density and pressure constants
  - Mass and viscosity
  - Integration timestep
  - Visual appearance

### Monitoring Tools
- **Particle Monitor**: View real-time data for selected particles
- **Energy Chart**: Visualize energy distribution
- **Force Vectors**: See individual force components
- **FPS Display**: Monitor simulation performance

### Time Controls
- **Play/Pause**: Control simulation execution
- **Step Forward/Back**: Navigate frame by frame
- **Large Steps**: Jump multiple frames
- **Reset**: Clear all particles

## 🔧 Configuration

### Simulation Parameters (globalVariables.h)
```cpp
// Kernel and interaction
float H = 16.0f;              // Kernel radius
float EPS = H / 2;            // Collision epsilon
float BOUND_DAMPING = -0.5f;  // Boundary damping

// Particle limits
int MAX_PARTICLES = 2500;     // Maximum particles
int DAM_PARTICLES = 100;      // Initial particles
int BLOCK_PARTICLES = 250;    // Particles per block

// Gravity
Vector2d G(0.f, -9.8f);       // Gravitational force
```

## 🏗️ Project Structure

```
Fluid-Simulator/
├── main.cpp                 # Application entry point
├── mainwindow.cpp/h         # Main UI window
├── openglsimulation.cpp/h   # OpenGL rendering and simulation
├── sph_functions.cpp/h      # SPH physics implementation
├── globalVariables.cpp/h    # Global state management
├── particleproperties.cpp/h # Fluid material definitions
├── particlemonitor.cpp/h    # Particle monitoring widget
├── energychart.cpp/h        # Energy visualization
├── ui_functions.cpp/h       # UI utility functions
├── toolsfunctions.cpp/h     # Tool implementations
├── mainwindow.ui            # UI layout definition
├── fluid_simulator.pro     # Qt project file
├── images.qrc              # Resource file
├── include/Eigen/          # Eigen library headers
└── Images/                 # Application icons and assets
```

## 🎯 Key Components

### Physics Engine (sph_functions.cpp)
- `ComputeDensityPressure()`: Calculate particle density and pressure
- `ComputeForces()`: Calculate pressure, viscosity, and gravitational forces
- `Integrate()`: Update particle positions and handle boundary conditions

### Rendering Engine (openglsimulation.cpp)
- Real-time OpenGL particle rendering
- Mouse interaction handling
- Tool implementation
- Performance monitoring

### User Interface (mainwindow.cpp)
- Simulation controls
- Parameter adjustment
- Tool selection
- Time navigation

## 🐛 Known Issues & Limitations

- Performance decreases with high particle counts (>1000 particles)
- Memory usage grows with simulation history for time navigation
- Boundary conditions are simplified (no complex geometry support)

## 🙏 Acknowledgments

This SPH implementation is based on the [mueller-sph](https://github.com/lucas-schuermann/mueller-sph.git) repository by Lucas Schuermann, which implements the SPH algorithm described in Müller et al.'s seminal paper. This project extends that foundation with:

- Complete Qt-based graphical user interface
- Real-time interaction tools and particle manipulation
- Advanced visualization and monitoring systems
- Cross-platform compatibility (Linux/Windows)
- Multi-threaded performance optimizations

**Original SPH Engine**: [https://github.com/lucas-schuermann/mueller-sph.git](https://github.com/lucas-schuermann/mueller-sph.git)

**Key References:**
- Müller, M., Charypar, D., & Gross, M. (2003). Particle-based fluid simulation for interactive applications
- Monaghan, J. J. (1992). Smoothed particle hydrodynamics
- Kelager, M. (2006). Lagrangian fluid dynamics using smoothed particle hydrodynamics

**Special Thanks**:
- Lucas Schuermann for the original SPH implementation
- The Qt and Eigen communities for their excellent frameworks
- The computer graphics and fluid simulation research community

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🤝 Contributing

Contributions are welcome! Please feel free to submit a Pull Request. For major changes, please open an issue first to discuss what you would like to change.

## 📞 Contact

[Add contact information here]

---

**Note**: This simulator is designed for educational and research purposes to demonstrate SPH fluid dynamics principles.