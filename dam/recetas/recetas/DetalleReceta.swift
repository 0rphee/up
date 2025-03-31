//
//  DetalleReceta.swift
//  recetas
//
//  Created by roger on 28/03/25.
//

import SwiftUI

struct DetalleReceta: View {
    @State var receta: RecipeModel
    var body: some View {
        VStack {
            Rectangle().frame(height: 300).foregroundStyle(Color.clear)
                .background(
                    Image(receta.image).resizable().scaledToFill().clipped()
                ).scaledToFill().ignoresSafeArea()

            VStack(alignment: .leading) {
                Text(receta.name).font(.title.bold())
                Text(receta.ingredients.joined(separator: ", "))
                Text(receta.instructions)
            }.padding()
            Spacer()
        }
    }}

#Preview {
    DetalleReceta(receta: tacos)
}
