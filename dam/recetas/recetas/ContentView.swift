//
//  ContentView.swift
//  recetas
//
//  Created by roger on 28/03/25.
//

import SwiftUI

struct ContentView: View {
    var body: some View {
        NavigationView {
            List(categories) {
                categories in
                Section(categories.name) {
                    ForEach(categories.recipes) {
                        recipe in
                        NavigationLink(
                            destination: DetalleReceta(receta: recipe)
                        ) {
                            Receta(receta: recipe)
                        }
                    }
                }
            }
        }
    }
}

#Preview {
    ContentView()
}
