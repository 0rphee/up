//
//  Receta.swift
//  recetas
//
//  Created by roger on 28/03/25.
//

import SwiftUI

struct Receta: View {
    @State var receta: RecipeModel
    var body: some View {
        HStack(alignment: .top){
            // nombre, dificultad, ingredientes, imagen
            Image(receta.image).resizable().frame(width: 50, height: 50)
            
            VStack{
                Text(receta.name).font(.headline)
                ForEach(receta.ingredients, id: \.self){
                    ingredient in
                    Text(ingredient).foregroundStyle(.gray).font(.caption2)
                }
            }
            
            Spacer()
            
            Text(receta.difficulty.rawValue).padding().background(Color.blue).clipShape(Capsule()).font(.caption)
        }
    }
}

#Preview {
    Receta(receta: tacos)
}
